#include <iostream>
#include <iomanip>
using namespace std;

void round_robin(string processes[], int burst_time[], int n, int quantum) {
    int rem_burst_time[n], waiting_time[n], turnaround_time[n];
    for (int i = 0; i < n; i++) {
        rem_burst_time[i] = burst_time[i];
        waiting_time[i] = 0;
    }

    int t = 0;
    string calculation_steps[n];

    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rem_burst_time[i] > 0) {
                done = false;
                if (rem_burst_time[i] > quantum) {
                    t += quantum;
                    rem_burst_time[i] -= quantum;
                } else {
                    // Proses selesai
                    t += rem_burst_time[i];
                    waiting_time[i] = t - burst_time[i];

                    // Mencatat langkah perhitungan
                    calculation_steps[i] = "Waktu tunggu " + processes[i] + " = " + to_string(t) + " - " + to_string(burst_time[i]) + " = " + to_string(waiting_time[i]) + " ms";
                    rem_burst_time[i] = 0;
                }
            }
        }
        if (done) break;
    }

    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i]; // TAT = WT + BT
        total_turnaround_time += turnaround_time[i];
    }

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;


    cout << "Langkah-langkah perhitungan waktu tunggu dan TAT:\n";
    cout << "---------------------------------------------------\n";
    cout << setw(7) << "Proses" << " | " << setw(15) << "Waktu Tunggu" << " | " << setw(15) << "TAT" << " | " << "Rumus\n";
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(7) << processes[i] << " | " << setw(15) << waiting_time[i] << " | " << setw(15) << turnaround_time[i] << " | ";
        if (waiting_time[i] > 0) {
            cout << calculation_steps[i] << "\n";
        } else {
            cout << "Waktu tunggu untuk proses pertama adalah 0 ms\n";
        }
    }
    cout << "---------------------------------------------------\n";


    cout << "\nAverage Waiting Time: " << average_waiting_time << " ms\n";
    cout << "Menghitung Waiting Time: (Total Waiting Time / Jumlah Proses) = (" << total_waiting_time << " / " << n << ") = " << average_waiting_time << " ms\n";

    cout << "Average Turnaround Time: " << average_turnaround_time << " ms\n";
    cout << "Menghitung Turnaround Time: (Total Turnaround Time / Jumlah Proses) = (" << total_turnaround_time << " / " << n << ") = " << average_turnaround_time << " ms\n";
}

int main() {
    string processes[] = {"P1", "P2", "P3", "P4"};
    int burst_time[] = {24, 3, 20, 10};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    int quantum = 10;
    round_robin(processes, burst_time, n, quantum);
    return 0;
}
