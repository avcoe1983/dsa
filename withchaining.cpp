#include<iostream>
#include<string.h>
using namespace std;
const int t=10;
struct Node{
    char name[15];
    long int mob;
    int chain;
    Node(){
        strcpy(name,"-");
        mob=0;
        chain=-1;
    }
};
class hasht{
    Node table[t];
    public:
    int hashfunc(long int mob){
        return mob%t;
    }
    void insert() {
        Node s;
        cout << "Enter name: ";
        cin >> s.name;
        cout << "Enter mobile number: ";
        cin >> s.mob;
    
        int index = hashfunc(s.mob);
    
        
        if (table[index].mob == 0) {
            table[index] = s;
            return;
        }
    
       
        if (hashfunc(table[index].mob) != index) {
            Node temp = table[index]; 
            table[index] = s;          
    
            
            int newIndex = (index + 1) % t;
            while (table[newIndex].mob != 0 && newIndex != index) {
                newIndex = (newIndex + 1) % t;
            }
    
            if (newIndex == index) {
                cout << "Hash table is full!\n";
                return;
            }
    
            table[newIndex] = temp;
    
           
            int home = hashfunc(temp.mob);
            int i = home;
            while (table[i].chain != -1) {
                i = table[i].chain;
            }
            table[i].chain = newIndex;
        }
        else {
            
            int newIndex = (index + 1) % t;
            while (table[newIndex].mob != 0 && newIndex != index) {
                newIndex = (newIndex + 1) % t;
            }
    
            if (newIndex == index) {
                cout << "Hash table is full!\n";
                return;
            }
    
            table[newIndex] = s;
    
            
            int i = index;
            while (table[i].chain != -1) {
                i = table[i].chain;
            }
            table[i].chain = newIndex;
        }
    }
    

    
    void dispaly(){
        cout<<"hash table:";
        for(int i=0;i<t;i++){
            cout<<i<<" "<<table[i].name<<" "<<table[i].mob<<" "<<table[i].chain<<endl;
        }
    }
    void search(){
        long int number;
        cout<<"enter a mobno to search:";
        cin>>number;
        int index=hashfunc(number);
        while(index!=-1){
            if(table[index].mob==number){
                cout<<"mob number is found at index:"<<index<<endl;
                return;
            }
            index=table[index].chain;
        }
        cout<<"mobile number is not found:";
    }
    void del(){
        long int num;
        cout<<"enter a mob number to delete:";
        cin>>num;
        int index=hashfunc(num);
        int prev=-1;
        while(index!=-1){
            if(table[index].mob==num){
                if(table[index].chain==-1){
                    strcpy(table[index].name,"-");
                    table[index].mob=0;
                    table[index].chain=-1;
                }
                else{
                    int next=table[index].chain;
                    table[index]=table[next];
                    strcpy(table[index].name,"-");
                    table[index].mob=0;
                    table[index].chain=-1;

                }
                if(prev!=-1){
                    table[prev].chain=-1;
                }
                cout<<"record deleted:";
                return;
            }
            prev=index;
            index=table[index].chain;
        }
        cout<<"number is not found:";
    }
};
int main(){
    hasht ht;
    int choice;
    char again;
    do{
        cout<<"1-insert element:\n";
        cout<<"2-display element:\n";
        cout<<"3-serach elments:\n";
        cout<<"4-delete elements:\n";
        cout<<"enter a your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            ht.insert();
            break;
            case 2:
            ht.dispaly();
            break;
            case 3:
            ht.search();
            break;
            case 4:
            ht.del();
            break;
            default:
            cout<<"thala for reason:";


        }
        
            cout<<"do you wwant to perform again:(y/n)";
            cin>>again;
       
        

    }while(again=='y'||again=='Y');
    return 0;
}
