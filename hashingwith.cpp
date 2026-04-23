#include <iostream>
using namespace std;
const int size=10;
int a[size][3];
int hash2(int k) { return(k%size);}
void display();
void insert(int k);
int main()
{
    int op,key,flag,i;
    for(i=0;i<size;i++) { a[i][1]=-1; a[i][2]=0;}
    while(1)
    {
        cout<<"Enter 1 to insert a key\n"; 
        cout<<"Enter 2 to search a given key\n";
        cout<<"Enter 3 to display the hash table\n";
        cout<<"Enter 4 to exit\n";
        cin>>op;
        switch(op)
        {
            case 1: cout<<"Enter key to be inserted\n"; cin>>key; insert(key);break;
            //case 2:
            case 3: display();break;
            case 4: exit(0);
        }
    }
    return 0;
}

void display()
{ int i;
 cout<<"Index----key-----chain----\n";
 for(i=0;i<size;i++)
 {
     if(a[i][2])
     cout<<i<<" ---- "<<a[i][0]<<" ----- "<<a[i][1]<<" -----\n";
 }
 
} 
 void insert(int k)
 {
     int i,ch,j,hk,counter;
     hk=hash2(k);
     
     if(a[hk][2]==0) { a[hk][0]=k; a[hk][2]=1; cout<<" Key inserted\n"; return;}
     // there is collision, so find the next immediate free location in the entire hash table
     //case 1 key occupied with matching hk
     if(a[hk][0]%size==hk)
     { 
     counter=0; i=hk+1;
     while(counter<size)
     {
         if(i==size) i=0;
         if(a[i][2]==0)
         { a[i][0]=k; a[i][2]=1;break;}
         i++;
         counter++;
         
     }
     
     if(counter==size) { cout<<" Hash table full\n"; return;}
     // now lets build chain
     ch=a[hk][1];
     if(ch==-1)
     a[hk][1]=i;
     else
     {
         while(a[ch][2]==1 && a[ch][1]!=-1)
         ch=a[ch][1];
         
         a[ch][1]=i;
     }

    } //end of if(a[hk][0]%size==hk)
     
    //case 2 key occupied with non-matching hk
    if(a[hk][0]%size!=hk)
    {
        counter=0; i=hk+1;
        cout<<" inside non matching\n";
     while(counter<size)
     {
         if(i==size) i=0;
         if(a[i][2]==0)
         { a[i][0]=a[hk][0]; a[i][2]=1; a[hk][0]=k; a[hk][1]=-1;break;}
         i++;
         counter++;
         
     }
     cout<<" HT not full\n";
     
     if(counter==size) { cout<<" Hash table full\n"; return;}
      j=i+1; int temp=a[i][0]%10;
      if(j==size) j=0;
      counter=0;
      while(counter<size)
      {
          if(a[j][0]%10==temp&&a[j][1]==hk)
          a[j][1]=i;
          j++;
          if(j==size) j=0;
          counter++;
      }
        
    }// end of outer if
     
    
    
    
}

