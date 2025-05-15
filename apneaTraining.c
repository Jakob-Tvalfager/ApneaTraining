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
}

int read_value(void) {
    int value = 0;
    FILE *file;

    file = fopen("relaxedPauseData.txt", "r");
    if (file) {
        fscanf(file, "%d", &value);
        fclose(file);
    }
    return value;
}

void write_value(int value) {
    FILE *file;

    file = fopen("relaxedPauseData.txt", "w");
    if (file) {
        fprintf(file, "%d", value);
        fclose(file);
    }
}

void TypeAtraining(){

        int seconds;

        seconds = read_value();

        if (seconds == 0) {
            indexSwitch = 0;
            seconds = timeRelaxedPause();
            write_value(seconds);
            printf("read on seconds is %d\n", seconds);
        } else {
            printf("read on null seconds is %d\n", seconds);
        }

        sleep(30);
        int restsec = 60;
        int rounds = 5;

        printf("Exhale\n");
        sleep(5);

        for (int i = 0; rounds > i; i++) {
            printf("Round: %d\n", i+1);
            printf("Hold exhale\n");
            countdown(seconds);
            printf("Rest\n");
            countdown(restsec);
            restsec -= 10;
        }
        printf("Done!\n");
}
typeBtraining(){
        printf("placeholder for type B");
}


int main() {
    printf("The CO2 Breathing Breakthrough Guide\n");
    printf("====================================\n");
    printf("Reset Your Breathing Thermostat to Improve Sleep Apnea Naturally\n\n");

    printf("🔍 Why CO2 Tolerance Matters\n");
    printf("----------------------------\n");
    printf("Many with sleep apnea hyperventilate—breathing too fast and shallowly, especially during sleep. This:\n");
    printf(" - Lowers carbon dioxide (CO2) levels\n");
    printf(" - Triggers unstable breathing patterns\n");
    printf(" - Leads to airway collapse at night\n");
    printf("👉 Solution: Increase CO2 tolerance to breathe slowly and steadily, even asleep.\n");
    printf("Use CO2 tables, adapted from freediving, for sleep health.\n\n");

    printf("🧠 The Core Idea: Reset Your Breathing Thermostat\n");
    printf("-----------------------------------------------\n");
    printf("CO2 tolerance is like a thermostat for breathing:\n");
    printf(" - Low CO2 tolerance = hypersensitive thermostat = fast breathing = airway collapse\n");
    printf(" - High CO2 tolerance = steady thermostat = slow, calm breathing = open airway\n");

    printf("👉 Pick your training\n");
    printf("-----------------------------------------------\n");
    printf("Default (enter) - Same as last time\n");
    printf("1. Type A - Fixed Breath Hold, Decreasing Rest\n");
    printf("2. Type B - Increasing Breath Hold, Fixed Rest\n");

    int indexSwitch;

    scanf(indexSwitch);

    switch (indexSwitch) {
            case 1:
                TypeAtraining();
                break;
            case 2:
                TypeBtraining();
                break;
            default:
                printf("placeholder for same as last time");
                break;
    }
    return 0;
}
