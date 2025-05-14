#include <stdio.h>    // for printf
#include <unistd.h>   // for sleep
#include <stdlib.h>   // for system (aplay)
#include <time.h>     // for timer

int timeRelaxedPause(void) {

        printf("1. Take a normal inhale, then a normal exhale.\n");
        printf("2. Hold your breath after the exhale.\n");
        printf("3. When you feel the first natural urge to breathe, stop. Don’t strain.\n");
        printf("4. Time this — that’s your Relaxed Pause.\n\n");
        printf("Press Enter to start the measurement\n");
        getchar();

        time_t start, end;
        int c, elapsed;

        start = time(NULL);
        while (1) {
                printf("Running... Press Enter to stop\n");
                fflush(stdout);
                c = getchar();
                if (c == '\n') {
                        end = time(NULL);
                        elapsed = (int)difftime(end, start);
                        break;
                }
                while (c != '\n' && c != EOF) {
                        c = getchar();
                }
        }
        printf("Elapsed time: %d seconds\n", elapsed);
        return elapsed;
}

void countdown(int seconds) {
        printf("Countdown from %d seconds:\n", seconds);
        while (seconds > 0) {
                printf("%d\n", seconds);
                sleep(1);
                seconds--;
        }
        printf("Time!\n");
        printf("\a"); // terminal sound if available
        return;
}

int main() {

        int sec = timeRelaxedPause();
        sleep(30);
        int restsec = 60;
        int rounds = 5;

        printf("Exhale\n");
        sleep(5);

        for (int i = 0; rounds > i; i++) {
                printf("Round: %d\n", i+1);
                printf("Hold exhale\n");
                countdown(sec);
                printf("Rest\n");
                countdown(restsec);
                restsec -= 10;
        }
        printf("Done!\n");
        return 0;
}
