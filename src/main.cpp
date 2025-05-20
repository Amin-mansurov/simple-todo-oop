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
    }

    void print_tasks() const {
    	int i = 1;
        for (const auto& task : tasks) {
        	cout << i << ": ";
            cout << task << endl;
            i++;
        }
    }

};

int main()
{
    Task study;
    const string filename = "todo.txt";
    study.load_task(filename);
    study.print_tasks();
    return 0;
}
