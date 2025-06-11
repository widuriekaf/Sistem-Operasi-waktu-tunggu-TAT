
processes = ['P1', 'P2', 'P3', 'P4']
burst_time = [24, 3, 20, 10]
quantum = 10

def round_robin(processes, burst_time, quantum):
    n = len(processes)
    rem_burst_time = burst_time.copy()
    waiting_time = [0] * n
    turnaround_time = [0] * n
    t = 0
    

    calculation_steps = []

    while True:
        done = True
        for i in range(n):
            if rem_burst_time[i] > 0:
                done = False
                if rem_burst_time[i] > quantum:

                    t += quantum
                    rem_burst_time[i] -= quantum
                else:

                    t += rem_burst_time[i]
                    waiting_time[i] = t - burst_time[i]
                    turnaround_time[i] = waiting_time[i] + burst_time[i]
                    

                    calculation_steps.append(f"Waktu tunggu {processes[i]} = {t} - {burst_time[i]} = {waiting_time[i]} ms")
                    rem_burst_time[i] = 0
        if done:
            break

    average_waiting_time = sum(waiting_time) / n
    average_turnaround_time = sum(turnaround_time) / n


    print("Langkah-langkah perhitungan waktu tunggu dan TAT:")
    print("---------------------------------------------------")
    print(f"{'Proses':<5} | {'Waktu Tunggu':<15} | {'TAT':<15} | {'Rumus'}")
    print("---------------------------------------------------")
    for i in range(n):
        if waiting_time[i] > 0:
            print(f"{processes[i]:<5} | {waiting_time[i]:<15} | {turnaround_time[i]:<15} | Waktu selesai {processes[i]} - Burst time {processes[i]} = {waiting_time[i]} ms")
        else:
            print(f"{processes[i]:<5} | {waiting_time[i]:<15} | {turnaround_time[i]:<15} | Waktu tunggu untuk proses pertama adalah 0 ms")
    
    print("---------------------------------------------------")
    print(f"\nAverage Waiting Time: {average_waiting_time:.2f} ms")
    print(f"Menghitung Waiting Time: (Total Waiting Time / Jumlah Proses) = ({sum(waiting_time)} / {n}) = {average_waiting_time:.2f} ms")
    
    print(f"\nAverage Turnaround Time: {average_turnaround_time:.2f} ms")
    print(f"Menghitung Turnaround Time: (Total Turnaround Time / Jumlah Proses) = ({sum(turnaround_time)} / {n}) = {average_turnaround_time:.2f} ms")


round_robin(processes, burst_time, quantum)
