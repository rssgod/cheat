#include<iostream>
using namespace std;
const int size=10;
int hashing(int num)
{
    return num % size;
}
int arr[size][3],count,i,ch;
void init()
{
    for(int i=0;i<size;i++)
    {
        arr[i][0]=-1;       //key
        arr[i][1]=-1;       //pointer
        arr[i][2]=0;        //free or not (0->empty and 1-> not empty)
    }
}
void insert(int num)
{
    int hsd=hashing(num);
    if(arr[hsd][2]==0)
    {
        arr[hsd][0]=num;
        arr[hsd][2]=1;
        return;
    }
    count=0;
    i=hsd+1;
    while (count<size)
    {
        if(i==size)
        {
            i=0;
        }
        if(arr[i][2]==0)
        {
            arr[i][0]=num;
            arr[i][2]=1;
            break;
        }
        i++;
        count++;
    }
    if(count==size)
    {
        cout<<"Hash Table is Full";
        return;
    }
    ch = hsd;

    while(arr[ch][1] != -1)
    {
        ch = arr[ch][1];
    }

    arr[ch][1] = i;
}
void display()
{
    cout<<"Index    Key  pointer"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<i<<"  "<<arr[i][0]<<"  "<<arr[i][1]<<endl;
    }
}
void deleteKey(int key)
{
    int h = hashing(key);
    int curr = h;
    int prev = -1;

    // Same traversal as search
    while (curr != -1)
    {
        if (arr[curr][0] == key)
        {
            // If first node
            if (prev == -1)
            {
                arr[curr][0] = -1;
                arr[curr][2] = 0;
            }
            else
            {
                arr[prev][1] = arr[curr][1];

                arr[curr][0] = -1;
                arr[curr][1] = -1;
                arr[curr][2] = 0;
            }

            cout << "Deleted\n";
            return;
        }

        prev = curr;
        curr = arr[curr][1];
    }

    cout << "Not Found\n";
}
int main()
{
    init();

    insert(21);
    insert(31);
    insert(41);
    insert(51);

    display();

    deleteKey(31);
    display();
}