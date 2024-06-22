#include<iostream>
#include<string>
#include<vector>

using namespace std;

void mainList(){
    cout<<"To Do list:"<<endl;
    cout<<"1.Add an item:"<<endl;
    cout<<"2.Remove an item:"<<endl;
    cout<<"3.Display the main list:"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choices:";
}

void addItem(vector<string> &todolist){
    cout<<"Enter the item to add:";
    string item;
    cin.ignore();
    getline(cin,item);
    todolist.push_back(item);
    cout<<"Your item is added"<<endl;
}

void removeItem(vector<string> &todolist){
    cout<<"Enter the index of item to be removed:";
    int index;
    cin>>index;
    if(index>0&& index<=todolist.size()){
        todolist.erase(todolist.begin()+index-1);
        cout<<"Your item is removed"<<endl;
    }else{
        cout<<"Enter the correct index"<<endl;
    }

}

void display_main_list(const vector<string> &todolist){
    if(todolist.empty()) cout<<"Your list is empty:"<<endl;
    else{
        cout<<"To-Do List:"<<endl;
        for(int i=0;i<todolist.size();i++) cout<<i+1<<". "<<todolist[i]<<endl;
    }
}

int main(){
    vector<string> todolist;
    int choice;

    do{
        mainList();
        cin>>choice;

        switch(choice){
            case 1:
            addItem(todolist);
            break;

            case 2:
            removeItem(todolist);
            break;
            
            case 3:
            display_main_list(todolist);
            break;
            
            case 4:
            cout<<"Exiting..."<<endl;
            break;

            default:
            cout<<"Error, try once more"<<endl;
        }
     } while(choice!=4);

     return 0;

    }
   

