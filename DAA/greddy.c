#include <stdio.h>

int findMaxEvents(int startTimes[], int endTimes[], int n) {
    int maxEvents = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (startTimes[i] >= total) {
            total = endTimes[i];
            maxEvents++;
        }
    }

    return maxEvents;
}

int main() {
    int n;
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Enter the number of events: ");
    scanf("%d", &n);


    int startTimes[50], endTimes[50];
    printf("Enter the start and end times for each event:\n");
    
    for (int i = 0; i < n; i++) {
        printf("Event %d start time: ", i + 1);
        scanf("%d", &startTimes[i]);
        printf("Event %d end time: ", i + 1);
        scanf("%d", &endTimes[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (endTimes[j] > endTimes[j + 1]) {
                int temp = endTimes[j];
                endTimes[j] = endTimes[j + 1];
                endTimes[j + 1] = temp;

                int temp2 = startTimes[j];
                startTimes[j] = startTimes[j + 1];
                startTimes[j + 1] = temp2;
            }
        }
    }

    int maxEvents = findMaxEvents(startTimes, endTimes, n);
    printf("Maximum number of events that can be scheduled: %d\n", maxEvents);

    return 0;
}