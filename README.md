# CodeAlpha_TO-DO-LIST-APPLICATION
📄 Code Overview
=
This is a simple console-based Task Manager app in C++.
✅ Allows users to:

Add a task

Mark a task as completed

View pending tasks

Save and load tasks from a text file (tasks.txt)
The tasks persist between runs thanks to file I/O.

🔷 Class: Task
=
Represents a single task.

Contains:

description → the text of the task.

completed → whether it is done (true) or not (false).

Constructor allows setting the description and optionally whether it is already completed.

🔷 Class: TaskManager
=
This manages all tasks (in a vector<Task>), and provides the operations.

🔷 Data Member:
A dynamic list of all tasks (from STL vector).

📁 loadTasks()
=
Reads tasks.txt file line by line.

For each task:

Reads description (one line).

Reads completed (an integer: 0 or 1).

Adds each task to the tasks vector.

💾 saveTasks()
=
Writes all current tasks back to tasks.txt.

For each task:

Write description on a line.

Write completed (0 or 1) on the next line.

➕ addTask()
=
Prompts the user to enter a new task description.

Adds it to tasks vector (marked incomplete by default).

Saves all tasks back to file.

✅ markCompleted()
=
Prompts the user for the index of the task to mark completed.

Checks if the index is valid.

If valid, sets completed = true and saves back to file.

📋 showPending()
=
Displays all tasks where completed == false.

If no pending tasks found, prints a message.

🖥️ main() Function
=
Creates a TaskManager object.

Loads tasks from file.

Displays a menu repeatedly:

Add Task

Mark as Completed

View Pending Tasks

Exit

📁 File Format: tasks.txt
=
Every task uses two lines:

Description

Completion status

⚠️ Notes & Improvements
=
✅ Code works well as a minimal console app.
However:

Tasks are indexed starting at 0, which may confuse users. You could display as 1-based.

File is overwritten every time — acceptable here, but not scalable.

No error checking if tasks.txt does not exist on first run.


🌟 Suggested Enhancements
=
🔷 Add deleteTask()

🔷 Display all tasks (not just pending)

🔷 Handle file-not-found case gracefully.

🔷 Validate user input better (e.g., only integers for menu)




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


  OUTPUT
  =
                                       --- Task Manager ---
                                       1. Add Task
                                       2. Mark Task as Completed
                                       3. View Pending Tasks
                                       4. Exit
                                       Enter choice: 1
                                       Enter task description: solve error
                                       Task added.

                                       --- Task Manager ---
                                       1. Add Task
                                       2. Mark Task as Completed
                                       D3. View Pending Tasks
                                       4. Exit
                                       Enter choice: 3

                                       Pending Tasks:
                                       2. solve error

                                      --- Task Manager ---
                                      1. Add Task
                                      2. Mark Task as Completed
                                      3. View Pending Tasks
                                      4. Exit
                                      Enter choice: 2
                                      Enter task number to mark as completed: 2
                                      Task marked as completed.

                                      --- Task Manager ---
                                      1. Add Task
                                      2. Mark Task as Completed
                                      3. View Pending Tasks
                                      4. Exit
                                      Enter choice: 4
                                      Goodbye!
