#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Task
{
public:
    vector<string> tasks;

    void load_task(const string& filename) {
        ifstream file(filename);
        string task;
        while (getline(file, task)) {
            tasks.push_back(task);
        }
        file.close();
    }

    void print_tasks() const {
    	int i = 1;
        if(tasks.empty()){
            cout << "Todo list empty\n";
            return ;
        }
        for (const auto& task : tasks) {
        	cout << i << ": ";
            cout << task << endl;
            i++;
        }
    }

    void add_task(const string& newTask){
        tasks.push_back(newTask);
    }

    void delete_task(int& id) {
        if (id >= 0 && id < tasks.size()) {
            tasks.erase(tasks.begin() + id);
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void save_task(const string& filename){
        ofstream file(filename);
        for(string task : tasks){
            file << task << endl;
        }
        file.close();
    }

};
int main() {
    Task study;
    const string filename = "todo.txt";
    study.load_task(filename);
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show tasks\n";
        cout << "2. Add task\n";
        cout << "3. Delete task\n";
        cout << "4. Save tasks\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        
        int n;
        cin >> n;

        if (n == 5) break;

        switch (n) {
            case 1:
                study.print_tasks();
                break;
            case 2: {
                string newTask;
                cin.ignore();
                cout << "Enter task: ";
                getline(cin, newTask);
                study.add_task(newTask);
                cout << "Task added.\n";
                break;
            }
            case 3: {
                int id;
                cout << "Enter task number to delete: ";
                cin >> id;
                id --;
                study.delete_task(id);
                break;
            }
            case 4:
                study.save_task(filename);
                cout << "Tasks saved.\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
