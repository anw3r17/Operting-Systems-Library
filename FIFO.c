#include <stdio.h>

#define MAX_FRAMES 3 // Define the maximum number of frames

int main() {
    int frames[MAX_FRAMES] = {0}; // Array to hold page frames
    int pages[20], faults = 0, n, i, j, k;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter %d page numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("\nPage\tFrames\t\tFault\n");

    for (i = 0; i < n; i++) {
        // Check if the page is already in frames
        int page_found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            int replace_index = 0;
            faults++;
            
            // Find the least recently used frame to replace
            for (j = 1; j < MAX_FRAMES; j++) {
                if (frames[j] < frames[replace_index])
                    replace_index = j;
            }

            // Replace page in the frame
            frames[replace_index] = pages[i];
        }

        // Print current page, frames, and whether there was a fault
        printf("%d\t", pages[i]);
        for (k = 0; k < MAX_FRAMES; k++)
            printf("%d ", frames[k]);
        printf("\t\t%s\n", (page_found ? "" : "F"));
    }

    printf("\nNumber of faults: %d\n", faults);

    return 0;
}