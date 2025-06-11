#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int burst_time;
    int priority;
};


bool compare(Process a, Process b) {
    return a.priority < b.priority;
}


void priority_scheduling(Process processes[], int n) {
    sort(processes, processes + n, compare);
    
    int waiting_time[n];
    waiting_time[0] = 0; 


    for (int i = 1; i < n; i++) {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
    }


    int turnaround_time[n];
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    float total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
    }
    
    float average_waiting_time = total_waiting_time / n;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += turnaround_time[i];
    }
    float average_turnaround_time = total_turnaround_time / n;


    cout << "Langkah-langkah perhitungan waktu tunggu:\n";
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "Waktu tunggu " << processes[i].name << " = 0 ms (proses pertama)\n";
        } else {
            cout << "Waktu tunggu " << processes[i].name << " = Waktu burst " << processes[i - 1].name 
                 << " + Waktu tunggu " << processes[i - 1].name << " = "
                 << processes[i - 1].burst_time << " + " << waiting_time[i - 1] << " = "
                 << waiting_time[i] << " ms\n";
        }
    }

    cout << "\nProses | Burst Time | Priority | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << setw(6) << processes[i].name << " | " 
             << setw(10) << processes[i].burst_time << " | " 
             << setw(8) << processes[i].priority << " | " 
             << setw(12) << waiting_time[i] << " | " 
             << setw(15) << turnaround_time[i] << endl;
    }
    
    cout << "\nAverage Waiting Time: " << average_waiting_time << " ms" << endl;
    cout << "Menghitung Average Waiting Time: (Total Waiting Time / Jumlah Proses) = ("
         << total_waiting_time << " / " << n << ") = " << average_waiting_time << " ms\n";
    
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << " ms" << endl;
    cout << "Menghitung Average Turnaround Time: (Total Turnaround Time / Jumlah Proses) = ("
         << total_turnaround_time << " / " << n << ") = " << average_turnaround_time << " ms\n";
}

int main() {
    Process processes[] = {{"P1", 10, 3}, {"P2", 1, 1}, {"P3", 2, 4}, {"P4", 1, 2}};
    int n = sizeof(processes) / sizeof(processes[0]);
    priority_scheduling(processes, n);
    return 0;
}
