#include<iostream>
using namespace std;
const int MAX = 10;
 
class Hash
{
private:
    long int arr[MAX];

public:
    Hash()
    {
        for(int i = 0; i < MAX; i++)
        {
            arr[i] = -1; 
        }
    }

    int hashfun(long int a)
    {
        return(a % 10);  
    }

    void insert()
     {
        int index, count = 0;
        long int num;
        cout << "Enter telephone number: ";
        cin >> num;  

        index = hashfun(num);

              
        while (arr[index] != -1 && count < MAX)
        {
            index = (index + 1) % MAX;  
            count++;
        }

        if (count < MAX)
        {
            arr[index] = num;
            cout << "Number inserted at  " << index <<" index"<< endl;
        }
        else
        {
            cout << "Hash table is FULL!\n";
        }
      }

    void display()
    {
        for (int i = 0; i < MAX; i++)
        {
            if (arr[i] == -1)
                cout << i << " ------> Empty"<<endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
    }

	void search()
	{
		long int num;
		cout<<"Enter telephone number to search: ";
		cin>>num;

		int index=hashfun(num);
		int count=0;

		while (arr[index] != -1 && count < MAX)
        {
           if (arr[index]==num)
          
		     {
			      cout<<"Number found at index :"<<index<<endl;
			      return;
	      	}
		   index=(index+1)%MAX;  
		   count++;
        }
		cout<<"Number not found in the hash table."<<endl;
	}
};

int main()
{
    Hash h;
    int choice;

    while (1)
    {
        cout << "1. Insert"<<endl;
 	     cout << "2. Display"<<endl;
        cout << "3. Search"<<endl;
 	     cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
       
        switch (choice)
        {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
		      case 3:
			       h.search();
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}