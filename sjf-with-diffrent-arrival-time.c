#include <stdio.h>

int main() {
    int n, i, j;
    int process[20], arrivalTime[20], burstTime[20], waitingTime[20], turnAroundTime[20], completionTime[20];
    float avgWaitingTime = 0, avgTurnAroundTime = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1; // Store process number
    }

    // Sort processes by arrival time, then by burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrivalTime[i] > arrivalTime[j] || 
               (arrivalTime[i] == arrivalTime[j] && burstTime[i] > burstTime[j])) {
                // Swap arrival time
                int temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // Swap burst time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
  g
                // Swap process numbers
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Initialize current time and process tracking
    int currentTime = 0;

    // Calculate completion, turnaround, and waiting times
    for (i = 0; i < n; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i]; // CPU waits for the process to arrive
        }
        completionTime[i] = currentTime + burstTime[i];
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        currentTime = completionTime[i];
    }

    // Calculate average waiting and turnaround times
    for (i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnAroundTime += turnAroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnAroundTime /= n;

    // Display the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrivalTime[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnAroundTime);

    return 0;
}
