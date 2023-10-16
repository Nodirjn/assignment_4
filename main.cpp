//
//  main.cpp
//  homew
//
//  Created by Nodir Habibullaev on 10/15/23.
//

#include <iostream>
using namespace std;



struct Task
{
    string description;
    string due_date;
    string status="incomplete";
};

void addNewTask(vector<Task> &tasks);
void changeStatus( vector<Task> &tasks);
void displayTasks(const vector<Task> &tasks);
void deleteTask(vector<Task> &tasks, const string &name);

int main() {
    vector<Task>tasks;
    int choice;
    do{
        cout << "To do list Manager \n";
        cout << "1. Add new task \n";
        cout << "2. Mark task completed \n";
        cout << "3. display tasks \n";
        cout << "4. Remove a task \n";
        cout << "5. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        
        string taskToDelete;
        switch(choice)
        {
        case 1:
            {
                addNewTask(tasks);
                break;
            }
        case 2:
            {
                changeStatus(tasks);
                break;
            };
        case 3:
            {
                displayTasks(tasks);
                break;
            };
        case 4:
            {
                cout << "Enter the name of the task to delete: ";
                cin >> taskToDelete;
                deleteTask(tasks, taskToDelete);
                break;
            };

        case 5:
            {
                cout << "Goodbye!" << endl;
                break;
            };

        default:
            cout << "Invalid choise!" << endl;
            break;
        }

     } while (choice != 5);

    
    
    return 0;
}


void addNewTask(vector<Task> &tasks){
    Task newTask;
    cout << "Enter description: ";
    cin >> newTask.description;
    cout << "Enter due date: ";
    cin >> newTask.due_date;
    tasks.push_back(newTask);
}

void changeStatus( vector<Task> &tasks){
    string taskToUpdate;
    cout << "Enter the name of the task to update: ";
    cin >> taskToUpdate;
    
    for (Task &it : tasks) {
        if (it.description == taskToUpdate) {
            it.status="complete";
            return;
        }

    }cout << "Task not found" << endl;
    
}
    
void displayTasks(const vector<Task> &tasks){
    for (const Task &s : tasks){
        cout << s.description << "  ->  " << s.due_date << " -> "<<s.status<< endl;
    }
}

void deleteTask(vector<Task> &tasks, const string &name) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->description == name) {
            tasks.erase(it);
            cout << "Task '" << name << "' has been deleted." << endl;
            return;
        }
    }
    cout << "Student '" << name << "' not found." << endl;
}
