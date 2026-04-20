board = ['_'] * 9

# check win
def win(p):
    w = [(0,1,2),(3,4,5),(6,7,8),
         (0,3,6),(1,4,7),(2,5,8),
         (0,4,8),(2,4,6)]
    return any(board[i]==board[j]==board[k]==p for i,j,k in w)

# minimax with alpha-beta
def f(max_turn, a, b):
    if win('X'): return 1
    if win('O'): return -1
    if '_' not in board: return 0

    if max_turn:  # AI
        v = -2
        for i in range(9):
            if board[i]=='_':
                board[i]='X'
                v = max(v, f(False, a, b))
                board[i]='_'
                a = max(a, v)
                if b <= a: break
        return v
    else:  # player
        v = 2
        for i in range(9):
            if board[i]=='_':
                board[i]='O'
                v = min(v, f(True, a, b))
                board[i]='_'
                b = min(b, v)
                if b <= a: break
        return v

# best move for AI
def best():
    move, bestv = -1, -2
    for i in range(9):
        if board[i]=='_':
            board[i]='X'
            v = f(False, -2, 2)
            board[i]='_'
            if v > bestv:
                move, bestv = i, v
    return move

# simple play
while True:
    print(board[0:3])
    print( board[3:6])
    print(board[6:9])

    # player
    p = int(input("Your move (0-8): "))
    board[p] = 'O'

    if win('O'):
        print("You win"); break

    # AI
    m = best()
    board[m] = 'X'
    print("AI:", m)

    if win('X'):
        print("AI wins"); break

    if '_' not in board:
        print("Draw"); break