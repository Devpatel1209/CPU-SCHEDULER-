#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;

    Process(int p, int a, int b, int pr) 
        : pid(p), arrival_time(a), burst_time(b), priority(pr),
          start_time(-1), finish_time(-1), waiting_time(0), turnaround_time(0) {}
};

#endif // PROCESS_H
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
// #include "process.h"

class Scheduler {
public:
    virtual void schedule(std::vector<Process>& processes) = 0;
};

#endif // SCHEDULER_H
#ifndef FCFS_H
#define FCFS_H

// #include "scheduler.h"
#include <algorithm>

class FCFS : public Scheduler {
public:
    void schedule(std::vector<Process>& processes) override {
        std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
            return a.arrival_time < b.arrival_time;
        });
        // Calculate start, finish, waiting, and turnaround times
        int current_time = 0;
        for (auto& process : processes) {
            if (current_time < process.arrival_time) {
                current_time = process.arrival_time;
            }
            process.start_time = current_time;
            current_time += process.burst_time;
            process.finish_time = current_time;
            process.turnaround_time = process.finish_time - process.arrival_time;
            process.waiting_time = process.turnaround_time - process.burst_time;
        }
    }
};

#endif // FCFS_H
#ifndef SRTF_H
#define SRTF_H

// #include "scheduler.h"
#include <algorithm>
#include <queue>

class SRTF : public Scheduler {
public:
    void schedule(std::vector<Process>& processes) override {
        auto cmp = [](Process* a, Process* b) { return a->burst_time > b->burst_time; };
        std::priority_queue<Process*, std::vector<Process*>, decltype(cmp)> pq(cmp);

        int time = 0;
        int completed = 0;
        int n = processes.size();
        int index = 0;

        while (completed != n) {
            while (index < n && processes[index].arrival_time <= time) {
                pq.push(&processes[index]);
                index++;
            }

            if (!pq.empty()) {
                Process* current = pq.top();
                pq.pop();

                if (current->start_time == -1) {
                    current->start_time = time;
                }

                time++;
                current->burst_time--;

                if (current->burst_time == 0) {
                    current->finish_time = time;
                    current->turnaround_time = current->finish_time - current->arrival_time;
                    current->waiting_time = current->turnaround_time - (current->finish_time - current->start_time);
                    completed++;
                } else {
                    pq.push(current);
                }
            } else {
                time++;
            }
        }
    }
};

#endif // SRTF_H
#include <iostream>
#include <vector>
// #include "process.h"
// #include "scheduler.h"
// #include "fcfs.h"
// #include "srtf.h"

void printProcesses(const std::vector<Process>& processes) {
    for (const auto& process : processes) {
        std::cout << "Process ID: " << process.pid
                  << ", Arrival Time: " << process.arrival_time
                  << ", Burst Time: " << process.burst_time
                  << ", Start Time: " << process.start_time
                  << ", Finish Time: " << process.finish_time
                  << ", Waiting Time: " << process.waiting_time
                  << ", Turnaround Time: " << process.turnaround_time << "\n";
    }
}

int main() {
    std::vector<Process> processes = {
        Process(1, 0, 5, 1),
        Process(2, 1, 3, 2),
        Process(3, 2, 8, 1),
        Process(4, 3, 6, 3)
    };

    // Test FCFS
    FCFS fcfs_scheduler;
    fcfs_scheduler.schedule(processes);
    std::cout << "FCFS Scheduling:\n";
    printProcesses(processes);

    // Reset process data for SRTF test
    processes = {
        Process(1, 0, 5, 1),
        Process(2, 1, 3, 2),
        Process(3, 2, 8, 1),
        Process(4, 3, 6, 3)
    };

    // Test SRTF
    SRTF srtf_scheduler;
    srtf_scheduler.schedule(processes);
    std::cout << "SRTF Scheduling:\n";
    printProcesses(processes);

    return 0;
}