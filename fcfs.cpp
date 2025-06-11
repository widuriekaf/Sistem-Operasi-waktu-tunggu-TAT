#include <iostream>
using namespace std;

string processes[] = {"P1", "P2", "P3", "P4", "P5"};
int burst_time[] = {8, 4, 9, 5, 2};

void findWaitingTime_FCFS(int burst_time[], int n, int waiting_time[]) {
    waiting_time[0] = 0; // Waktu tunggu untuk proses pertama adalah 0

    for (int i = 1; i < n; i++) {
        // Waktu tunggu = Waktu burst proses sebelumnya + Waktu tunggu sebelumnya
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}

void findAverageWaitingTime_FCFS(int burst_time[], int n) {
    int waiting_time[n];
    findWaitingTime_FCFS(burst_time, n, waiting_time);

    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
    }

    float average_waiting_time = (float)total_waiting_time / n;


    cout << "Langkah-langkah perhitungan waktu tunggu:\n";
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "Waktu tunggu " << processes[i] << " = 0 ms (proses pertama)\n";
        } else {
            cout << "Waktu tunggu " << processes[i] << " = Waktu burst " << processes[i - 1]
                 << " + Waktu tunggu " << processes[i - 1] << " = " 
                 << burst_time[i - 1] << " + " << waiting_time[i - 1] << " = "
                 << waiting_time[i] << " ms\n";
        }
    }

    int turnaround_time[n];
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += turnaround_time[i];
    }

    float average_turnaround_time = total_turnaround_time / n;

    cout << "\nProses | Burst Time | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "       " << burst_time[i] << "          " 
             << waiting_time[i] << "            " << turnaround_time[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << average_waiting_time << " ms\n";
    cout << "Menghitung Average Waiting Time: (Total Waiting Time / Jumlah Proses) = (" 
         << total_waiting_time << " / " << n << ") = " << average_waiting_time << " ms\n";

    cout << "\nAverage Turnaround Time: " << average_turnaround_time << " ms\n";
    cout << "Menghitung Average Turnaround Time: (Total Turnaround Time / Jumlah Proses) = (" 
         << total_turnaround_time << " / " << n << ") = " << average_turnaround_time << " ms\n";
}

int main() {
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    findAverageWaitingTime_FCFS(burst_time, n);
    return 0;
}
