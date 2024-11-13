#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    string name;
    int burstTime;
    int priority;

    Process(string n, int b, int p) : name(n), burstTime(b), priority(p) {}
};

class Scheduling {

public:
    // First-Come-First-Serve (FCFS)
    static void fcfsScheduling(vector<Process>& processes) {
        int n = processes.size();
        vector<int> waitingTime(n, 0);
        vector<int> turnaroundTime(n, 0);

        // Calculate waiting time
        for (int i = 1; i < n; i++) {
            waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
        }

        int totalTurnaroundTime = 0;
        int totalWaitingTime = 0;

        // Calculate turnaround time and accumulate total waiting and turnaround times
        for (int i = 0; i < n; i++) {
            turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
            totalTurnaroundTime += turnaroundTime[i];
            totalWaitingTime += waitingTime[i];
        }

        cout << "FCFS Scheduling:" << endl;
        printResults(processes, waitingTime, turnaroundTime);
        cout << "Average Waiting Time: " << (float)totalWaitingTime / n << endl;
        cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl << endl;
    }

    // Shortest Job First (SJF) - Non-preemptive
    static void sjfScheduling(vector<Process>& processes) {
        int n = processes.size();
        vector<int> waitingTime(n, 0);
        vector<int> turnaroundTime(n, 0);

        // Sort processes by burst time (Shortest Job First)
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.burstTime < b.burstTime;
        });

        // Calculate waiting time
        for (int i = 1; i < n; i++) {
            waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
        }

        int totalTurnaroundTime = 0;
        int totalWaitingTime = 0;

        // Calculate turnaround time and accumulate total waiting and turnaround times
        for (int i = 0; i < n; i++) {
            turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
            totalTurnaroundTime += turnaroundTime[i];
            totalWaitingTime += waitingTime[i];
        }

        cout << "SJF Scheduling:" << endl;
        printResults(processes, waitingTime, turnaroundTime);
        cout << "Average Waiting Time: " << (float)totalWaitingTime / n << endl;
        cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl << endl;
    }

private:
    // Utility function to print the results
    static void printResults(const vector<Process>& processes, const vector<int>& waitingTime, const vector<int>& turnaroundTime) {
        cout << "Process | Burst Time | Waiting Time | Turnaround Time" << endl;
        for (size_t i = 0; i < processes.size(); i++) {
            cout << processes[i].name << "       | " << processes[i].burstTime << "           | "
                 << waitingTime[i] << "            | " << turnaroundTime[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    vector<Process> processes = {
        Process("P1", 2, 2),
        Process("P2", 1, 1),
        Process("P3", 8, 4),
        Process("P4", 4, 2),
        Process("P5", 5, 3)
    };

    Scheduling::fcfsScheduling(processes);  // FCFS Scheduling
    Scheduling::sjfScheduling(processes);   // SJF Scheduling

    return 0;
}
