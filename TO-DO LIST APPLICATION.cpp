#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Task
{
public:
 string description;
 bool completed;

 Task(string d, bool c = false)
 {
 description = d;
 completed = c;
 }
};

class TaskManager
{
private:
 vector<Task> tasks;

public:
 void loadTasks()
 {
 tasks.clear();
 ifstream file("tasks.txt");
 string desc;
 int comp;
 while (getline(file, desc))
 {
 file >> comp;
 file.ignore();
 tasks.push_back(Task(desc, comp));
 }
 file.close();
 }

 void saveTasks()
 {
 ofstream file("tasks.txt");
 for (int i = 0; i < tasks.size(); i++)
 {
 file << tasks[i].description << endl;
 file << tasks[i].completed << endl;
 }
 file.close();
 }

 void addTask()
 {
 string desc;
 cout << "Enter task description: ";
 cin.ignore();
 getline(cin, desc);
 tasks.push_back(Task(desc, false));
 saveTasks();
 cout << "Task added.\n";
 }

 void markCompleted()
 {
 int index;
 cout << "Enter task number to mark as completed: ";
 cin >> index;
 if (index >= 0 && index < tasks.size())
 {
 tasks[index].completed = true;
 saveTasks();
 cout << "Task marked as completed.\n";
 }
 else
 {
 cout << "Invalid index.\n";
 }
 }

 void showPending()
 {
 cout << "\nPending Tasks:\n";
 bool found = false;
 for (int i = 0; i < tasks.size(); i++)
 {
 if (!tasks[i].completed)
 {
 cout << i << ". " << tasks[i].description << endl;
 found = true;
 }
 }
 if (!found)
 {
 cout << "No pending tasks.\n";
 }
 }
};

int main()
{
 TaskManager manager;
 int choice;
 manager.loadTasks();

 do
 {
 cout << "\n--- Task Manager ---\n";
 cout << "1. Add Task\n";
 cout << "2. Mark Task as Completed\n";
 cout << "3. View Pending Tasks\n";
 cout << "4. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;

 if (choice == 1)
 {
 manager.addTask();
 }
 else if (choice == 2)
 {
 manager.markCompleted();
 }
 else if (choice == 3)
 {
 manager.showPending();
 }
 else if (choice == 4)
 {
 cout << "Goodbye!\n";
 }
 else
 {
 cout << "Invalid choice.\n";
 }

 } while (choice != 4);

 return 0;
}

