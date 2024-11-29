
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], completionTime[n], waitingTime[n], turnAroundTime[n];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    completionTime[0] = arrivalTime[0] + burstTime[0];
    for(i = 1; i < n; i++) {
        completionTime[i] = (completionTime[i-1] > arrivalTime[i]) ? completionTime[i-1] + burstTime[i] : arrivalTime[i] + burstTime[i];
    }

    for(i = 0; i < n; i++) {
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                i + 1,
                arrivalTime[i],
                burstTime[i],
                completionTime[i],
                waitingTime[i],
                turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);

    return 0;
}
