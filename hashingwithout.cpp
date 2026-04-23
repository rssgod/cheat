//hash - without replacement
#include <iostream>
using namespace std;

const int size = 10;
int a[size][3];

int hash2(int k) { return (k % 10); }

void display();
void insert(int k);
int search(int k);
void del_item(int k);

int main()
{
    int op, key, i, res;

    // Initialization FIX
    for(i = 0; i < size; i++) {
        a[i][0] = -1;   // key
        a[i][1] = -1;   // chain
        a[i][2] = 0;    // status
    }

    while(1)
    {
        cout<<"Enter 1 to insert a key\n"; 
        cout<<"Enter 2 to search a given key\n";
        cout<<"Enter 3 to display the hash table\n";
        cout<<"Enter 4 to delete a key\n";
        cout<<"Enter 5 to exit\n";

        cin>>op;

        switch(op)
        {
            case 1:
                cout<<"Enter key to be inserted\n";
                cin>>key;
                insert(key);
                break;

            case 2:
                cout<<"Enter Key To Search:";
                cin>>key;
                res = search(key);
                if(res != -1)
                    cout<<key<<" Found At : "<<res<<endl;
                else
                    cout<<"Not Found."<<endl;
                break;

            case 3:
                display();
                break;

             case 4:
                 cout<<"Enter key to delete\n";
                cin>>key;
                del_item(key);
                break;

            case 5:
                exit(0);
        }
    }
    return 0;
}

// SEARCH
int search(int k)
{
    int hk = hash2(k);

    if(a[hk][2] == 0)
        return -1;

    if(k == a[hk][0])
        return hk;

    int count = 0;
    int j = a[hk][1];

    while(j != -1 && count < size)
    {
        if(a[j][0] == k)
            return j;

        j = a[j][1];
        count++;
    }

    return -1;
}

// DISPLAY
void display()
{
    int i;
    cout<<"Index ---- key ----- chain\n";

    for(i = 0; i < size; i++)
    {
        cout<<i<<"   -----  ";

        if(a[i][2])
            cout<<a[i][0];
        else
            cout<<"-";

        cout<<"  -----   "<<a[i][1]<<"\n";
    }
}

// INSERT (UNCHANGED LOGIC)
void insert(int k)
{
    int i, ch, hk, counter;

    hk = hash2(k);

    if(search(k) != -1) {
        cout<<"Key Already Exists\n";
        return;
    }

    if(a[hk][2] == 0) {
        a[hk][0] = k;
        a[hk][2] = 1;
        cout<<"Key inserted\n";
        return;
    }

    // find free slot
    counter = 0;
    i = hk + 1;

    while(counter < size)
    {
        if(i == size) i = 0;

        if(a[i][2] == 0)
        {
            a[i][0] = k;
            a[i][2] = 1;
            break;
        }

        i++;
        counter++;
    }

    if(counter == size) {
        cout<<"Hash table full\n";
        return;
    }

    // build chain
    ch = a[hk][1];

    if(ch == -1)
        a[hk][1] = i;
    else
    {
        while(a[ch][1] != -1)
            ch = a[ch][1];

        a[ch][1] = i;
    }
}

//DELETE FUNCTION (CORRECT)
void del_item(int k)
{
    int hk = hash2(k);

    if(a[hk][2] == 0)
    {
        cout<<"Key not found\n";
        return;
    }

    // Case 1: key at head
    if(a[hk][0] == k)
    {
        int next = a[hk][1];

        if(next == -1)
        {
            a[hk][2] = 0;
        }
        else
        {
            a[hk][0] = a[next][0];
            a[hk][1] = a[next][1];
            a[next][2] = 0;
            a[next][1] = -1;
        }

        cout<<"Deleted\n";
        return;
    }

    // Case 2: key in chain
    int prev = hk;
    int curr = a[hk][1];

    while(curr != -1)
    {
        if(a[curr][0] == k)
        {
            a[prev][1] = a[curr][1];
            a[curr][2] = 0;
            a[curr][1] = -1;

            cout<<"Deleted\n";
            return;
        }

        prev = curr;
        curr = a[curr][1];
    }

    cout<<"Key not found\n";
}
