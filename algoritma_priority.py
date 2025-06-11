
processes = ['P1', 'P2', 'P3', 'P4']
burst_time = [10, 1, 2, 1]
priority = [3, 1, 4, 2]

def priority_scheduling(processes, burst_time, priority):
    n = len(processes)
    # Gabungkan dan urutkan berdasarkan priority
    combined = list(zip(priority, burst_time, processes))
    combined.sort()

    waiting_time = [0] * n
    turnaround_time = [0] * n


    for i in range(1, n):
        waiting_time[i] = combined[i - 1][1] + waiting_time[i - 1]
    

    for i in range(n):
        turnaround_time[i] = waiting_time[i] + combined[i][1]

    average_waiting_time = sum(waiting_time) / n
    average_turnaround_time = sum(turnaround_time) / n


    print("Langkah-langkah perhitungan waktu tunggu:")
    for i in range(n):
        if i == 0:
            print(f"Waktu tunggu {combined[i][2]} = 0 ms (proses pertama)")
        else:
            print(f"Waktu tunggu {combined[i][2]} = Waktu burst {combined[i - 1][2]} + Waktu tunggu {combined[i - 1][2]} = "
                  f"{combined[i - 1][1]} + {waiting_time[i - 1]} = {waiting_time[i]} ms")
    

    print("\nProses | Burst Time | Priority | Waiting Time | Turnaround Time")
    for i in range(n):
        print(f"{combined[i][2]:<7} | {combined[i][1]:<10} | {combined[i][0]:<8} | {waiting_time[i]:<12} | {turnaround_time[i]:<15}")
    
    print(f"\nAverage Waiting Time: {average_waiting_time:.2f} ms")
    print(f"Menghitung Average Waiting Time: (Total Waiting Time / Jumlah Proses) = ({sum(waiting_time)} / {n}) = {average_waiting_time:.2f} ms")

    print(f"\nAverage Turnaround Time: {average_turnaround_time:.2f} ms")
    print(f"Menghitung Average Turnaround Time: (Total Turnaround Time / Jumlah Proses) = ({sum(turnaround_time)} / {n}) = {average_turnaround_time:.2f} ms")


priority_scheduling(processes, burst_time, priority)
