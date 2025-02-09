#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
using namespace std;

vector<string> tasks;

void loadTask(){
    ifstream file("tasks.txt");
    if(file.is_open()){
        string task;
        while(getline(file, task)){
            tasks.push_back(task);
        }
        file.close();
    }
}
void saveTask(){
    ofstream file("tasks.txt");
    if(file.is_open()){
        for(const string &task : tasks){
            file<<task<<'\n';
        }
        file.close();
    }
}

void addTask(){
    system("cls");
    string task;
    cout<<"Enter the task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    saveTask();
}
void showTask(){
    system("cls");
    cout<<"*****Uncompleted Tasks*****"<<endl;
    for(int i = 0; i<tasks.size(); i++){
        cout<<i<<" - "<<tasks[i]<<endl;
    }
    cout<<endl;
}
void delTask(){
    system("cls");
    int ind;
    cout<<"Tasks Deleter"<<endl;
    cout<<"Enter the index of Task:";
    cin>>ind;
    tasks.erase(tasks.begin()+ind);
    saveTask();
}
int main(){
    loadTask();
    int choice;
    do
    {
        cout<<"To-do List"<<endl;
        cout<<"1. Add Task"<<endl<<"2. Show Tasks"<<endl<<"3. Delete Task"<<endl<<"Enter Anything else to Exit."<<endl<<"Enter your choice: ";
        cin>>choice;
        if (choice == 1){
            addTask();
        }else if (choice == 2){
            showTask();
        }else if(choice == 3){
            delTask();
        }else{
            cout<<"Enter a valid choice!";
	}
    }while (choice != 4);
    
    cout<<"Exiting....";
    
}
