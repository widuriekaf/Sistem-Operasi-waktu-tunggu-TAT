processes = ['P1', 'P2', 'P3', 'P4', 'P5']
burst_time = [8, 4, 9, 5, 2]

def findWaitingTime_FCFS(burst_time):
    n = len(burst_time)
    waiting_time = [0] * n
    
    for i in range(1, n):
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1]
        
    return waiting_time

def findAverageWaitingTime_FCFS(burst_time):
    waiting_time = findWaitingTime_FCFS(burst_time)
    total_waiting_time = sum(waiting_time)
    average_waiting_time = total_waiting_time / len(burst_time)


    print("Langkah-langkah perhitungan waktu tunggu:")
    for i in range(len(burst_time)):
        if i == 0:
            print(f"Waktu tunggu {processes[i]} = 0 ms (proses pertama)")
        else:
            print(f"Waktu tunggu {processes[i]} = Waktu burst {processes[i - 1]} + Waktu tunggu {processes[i - 1]} = "
                  f"{burst_time[i - 1]} + {waiting_time[i - 1]} = {waiting_time[i]} ms")
    

    turnaround_time = [waiting_time[i] + burst_time[i] for i in range(len(burst_time))]
    
    total_turnaround_time = sum(turnaround_time)
    average_turnaround_time = total_turnaround_time / len(burst_time)


    print("\nProses | Burst Time | Waiting Time | Turnaround Time")
    for i in range(len(burst_time)):
        print(f"{processes[i]}       {burst_time[i]}          {waiting_time[i]}            {turnaround_time[i]}")
    
    print(f"\nAverage Waiting Time: {average_waiting_time:.2f} ms")
    print(f"Menghitung Average Waiting Time: (Total Waiting Time / Jumlah Proses) = ({total_waiting_time} / {len(burst_time)}) = {average_waiting_time:.2f} ms")

    print(f"\nAverage Turnaround Time: {average_turnaround_time:.2f} ms")
    print(f"Menghitung Average Turnaround Time: (Total Turnaround Time / Jumlah Proses) = ({total_turnaround_time} / {len(burst_time)}) = {average_turnaround_time:.2f} ms")


findAverageWaitingTime_FCFS(burst_time)
