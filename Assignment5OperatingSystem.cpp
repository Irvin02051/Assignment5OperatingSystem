#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
    int id;
    int burstTime;
    int priority;

    Process(int id, int burstTime, int priority) {
        this->id = id;
        this->burstTime = burstTime;
        this->priority = priority;
    }
};

// Function to calculate FCFS (First-Come, First-Served)
void fcfs(vector<Process>& processes) {
    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;
    int completionTime = 0;

    cout << "----------------- FCFS -----------------" << endl;
    cout << "Process ID | Waiting Time | Turnaround Time" << endl;
    for (auto& process : processes) {
        int waitTime = completionTime;
        int turnaroundTime = waitTime + process.burstTime;
        totalWaitTime += waitTime;
        totalTurnaroundTime += turnaroundTime;
        completionTime += process.burstTime;

        cout << process.id << "\t\t" << waitTime << "\t\t" << turnaroundTime << endl;
    }

    int n = processes.size();
    double averageWaitTime = (double)totalWaitTime / n;
    cout << "Average Waiting Time: " << averageWaitTime << endl;
}

// Function to calculate SJF (Shortest Job First)
void sjf(vector<Process>& processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });

    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;
    int completionTime = 0;

    cout << "----------------- SJF -----------------" << endl;
    cout << "Process ID | Waiting Time | Turnaround Time" << endl;
    for (auto& process : processes) {
        int waitTime = completionTime;
        int turnaroundTime = waitTime + process.burstTime;
        totalWaitTime += waitTime;
        totalTurnaroundTime += turnaroundTime;
        completionTime += process.burstTime;

        cout << process.id << "\t\t" << waitTime << "\t\t" << turnaroundTime << endl;
    }

    int n = processes.size();
    double averageWaitTime = (double)totalWaitTime / n;
    cout << "Average Waiting Time: " << averageWaitTime << endl;
}

int main() {
    // Initialize processes for FCFS
    vector<Process> fcfsProcesses = {
        Process(1, 2, 2),
        Process(2, 1, 1),
        Process(3, 8, 4),
        Process(4, 4, 2),
        Process(5, 5, 3)
    };

    fcfs(fcfsProcesses);

    // For SJF, we use a copy of the original processes list
    vector<Process> sjfProcesses = {
        Process(1, 2, 2),
        Process(2, 1, 1),
        Process(3, 8, 4),
        Process(4, 4, 2),
        Process(5, 5, 3)
    };

    sjf(sjfProcesses);

    return 0;
}
