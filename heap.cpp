#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;
    heap()
    {
        size = 0;
        arr[0] = -1;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1)
        {
            int parent = index / 2;
            if(arr[index] > arr[parent])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
             return;
        }
    }
    void print()
    {
        for(int i=1;i<=size;i++)
          cout << arr[i] <<ends;
          cout << endl;
    }
    void delet()
    {
         if(size == 0) cout << "nothing to delete"<<endl;

         arr[1] = arr[size];
         size--;

         int i = 1;
         while(i < size)
         {
            int left = 2*i;
            int right = 2*i+1;
            if(left < size && arr[i] < arr[left])
            { 
              swap(arr[left],arr[i]);
              left = i;
            }
            else if(right < size && arr[i] < arr[right])
            {
                swap(arr[right],arr[i]);
                right = i;
            }
            else return;
         }
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(56);
    h.insert(54);
    h.insert(53);
    h.insert(52);
    h.print();
}