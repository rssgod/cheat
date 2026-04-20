#include <iostream>
#include <cstdlib>
using namespace std;

const int n = 10;

int arr[n][3];
// arr[i][0] = key
// arr[i][1] = pointer (link)
// arr[i][2] = status (0 = empty, 1 = occupied)

void init()
{
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = -1;
        arr[i][1] = -1;
        arr[i][2] = 0;
    }
}

int hashing(int key)
{
    return key % n;
}

// Find empty slot
int empty()
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][2] == 0)
            return i;
    }
    return -1;
}

// 🔥 INSERT WITH REPLACEMENT
void insert(int key)
{
    int h = hashing(key);

    // Case 1: Empty slot
    if (arr[h][2] == 0)
    {
        arr[h][0] = key;
        arr[h][2] = 1;
        return;
    }

    // Check if existing element belongs here
    int existingHash = hashing(arr[h][0]);

    // 🔥 Replacement case
    if (existingHash != h)
    {
        int tempKey = arr[h][0];
        int tempLink = arr[h][1];

        // Place new key at correct position
        arr[h][0] = key;
        arr[h][1] = -1;

        // Find empty slot for displaced element
        int emp = empty();
        if (emp == -1)
        {
            cout << "Hash table is full\n";
            return;
        }

        arr[emp][0] = tempKey;
        arr[emp][1] = tempLink;
        arr[emp][2] = 1;

        // Fix chain
        int prev = existingHash;
        while (arr[prev][1] != h)
        {
            prev = arr[prev][1];
        }
        arr[prev][1] = emp;

        return;
    }

    // 🔹 Normal chaining
    int emp = empty();
    if (emp == -1)
    {
        cout << "Hash table is full\n";
        return;
    }

    arr[emp][0] = key;
    arr[emp][1] = -1;
    arr[emp][2] = 1;

    int curr = h;
    while (arr[curr][1] != -1)
    {
        curr = arr[curr][1];
    }
    arr[curr][1] = emp;
}

// 🔍 SEARCH
int search(int key)
{
    int h = hashing(key);
    int curr = h;

    while (curr != -1)
    {
        if (arr[curr][0] == key)
            return curr;
        curr = arr[curr][1];
    }
    return -1;
}

// 📊 DISPLAY
void display()
{
    cout << "\nIndex  Key  Link\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "      " << arr[i][0] << "    " << arr[i][1] << endl;
    }
}

// 🚀 MAIN
int main()
{
    init();
    int ch, no, pos;

    do
    {
        cout << "\n1.Insert 2.Search 3.Display 4.Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter element: ";
            cin >> no;
            insert(no);
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> no;
            pos = search(no);
            if (pos != -1)
                cout << "Found at index: " << pos << endl;
            else
                cout << "Not found\n";
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 4);
}