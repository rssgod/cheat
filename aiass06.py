import math

class TicTacToe:
    def __init__(self):
        # Initialize a 3x3 board with empty spaces
        self.board = [' ' for _ in range(9)]
        self.current_winner = None

    def print_board(self):
        # Helper to print the board layout
        for row in [self.board[i*3:(i+1)*3] for i in range(3)]:
            print('| ' + ' | '.join(row) + ' |')

    @staticmethod
    def print_board_nums():
        # Prints the indices corresponding to the board positions
        # 0 | 1 | 2 etc.
        number_board = [[str(i) for i in range(j*3, (j+1)*3)] for j in range(3)]
        for row in number_board:
            print('| ' + ' | '.join(row) + ' |')

    def available_moves(self):
        # Returns a list of indices that are currently empty
        return [i for i, spot in enumerate(self.board) if spot == ' ']

    def empty_squares(self):
        return ' ' in self.board

    def num_empty_squares(self):
        return self.board.count(' ')

    def make_move(self, square, letter):
        # If valid move, make the move and check for a winner
        if self.board[square] == ' ':
            self.board[square] = letter
            if self.winner(square, letter):
                self.current_winner = letter
            return True
        return False

    def winner(self, square, letter):
        # Check row
        row_ind = square // 3
        row = self.board[row_ind*3 : (row_ind+1)*3]
        if all([spot == letter for spot in row]):
            return True

        # Check column
        col_ind = square % 3
        column = [self.board[col_ind+i*3] for i in range(3)]
        if all([spot == letter for spot in column]):
            return True

        # Check diagonals
        if square % 2 == 0:
            diagonal1 = [self.board[i] for i in [0, 4, 8]]
            if all([spot == letter for spot in diagonal1]):
                return True
            diagonal2 = [self.board[i] for i in [2, 4, 6]]
            if all([spot == letter for spot in diagonal2]):
                return True

        return False

def minimax(state, depth, alpha, beta, player):
    max_player = 'O'  # AI wants to maximize score
    other_player = 'X' if player == 'O' else 'O'

    # Base case: check if the previous move ended the game
    if state.current_winner == other_player:
        # Score is based on remaining empty squares (faster wins are better)
        return {'position': None, 'score': 1 * (state.num_empty_squares() + 1) if other_player == max_player else -1 * (state.num_empty_squares() + 1)}
    elif not state.empty_squares():
        return {'position': None, 'score': 0}

    if player == max_player:
        best = {'position': None, 'score': -math.inf}
        for possible_move in state.available_moves():
            # 1. Make a move
            state.make_move(possible_move, player)
            # 2. Recurse using minimax
            sim_score = minimax(state, depth + 1, alpha, beta, other_player)
            # 3. Undo move
            state.board[possible_move] = ' '
            state.current_winner = None
            sim_score['position'] = possible_move

            # 4. Update best and alpha
            if sim_score['score'] > best['score']:
                best = sim_score
            alpha = max(alpha, best['score'])

            # 5. Alpha-Beta Pruning
            if beta <= alpha:
                break
        return best
    else:
        best = {'position': None, 'score': math.inf}
        for possible_move in state.available_moves():
            state.make_move(possible_move, player)
            sim_score = minimax(state, depth + 1, alpha, beta, other_player)
            state.board[possible_move] = ' '
            state.current_winner = None
            sim_score['position'] = possible_move

            if sim_score['score'] < best['score']:
                best = sim_score
            beta = min(beta, best['score'])

            if beta <= alpha:
                break
        return best

def play():
    game = TicTacToe()
    print("Welcome to Alpha-Beta Tic-Tac-Toe!")
    game.print_board_nums()

    letter = 'X' # Human starts as X
    while game.empty_squares():
        if letter == 'O':
            # AI's turn
            print("
AI is thinking...")
            # If it's the first move and the board is empty, take the middle for speed
            if game.num_empty_squares() == 9:
                square = 4
            else:
                square = minimax(game, 0, -math.inf, math.inf, 'O')['position']
            print(f"AI chooses square {square}")
        else:
            # Human's turn
            square = None
            while square is None:
                val = input(f"
{letter}'s turn. Input move (0-8): ")
                try:
                    val = int(val)
                    if val not in game.available_moves():
                        raise ValueError
                    square = val
                except ValueError:
                    print("Invalid square. Try again.")

        if game.make_move(square, letter):
            game.print_board()
            print("")
            if game.current_winner:
                print(f"{letter} wins!")
                return
            letter = 'O' if letter == 'X' else 'X'

    print("It's a tie!")

if __name__ == "__main__":
    play()