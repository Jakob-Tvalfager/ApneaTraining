#include <stdio.h>    // for printf
#include <unistd.h>   // for sleep
#include <time.h>     // for timer

void countdown(int seconds) {
        printf("Countdown from %d seconds:\n", seconds);
        while (seconds > 0) {
                printf("\r%2d", seconds);
                fflush(stdout);
                sleep(1);
                seconds--;
        }
        printf("\r");
        printf("Time!\n");
        printf("\a"); // terminal sound if available

        return;

}
int deleteRelaxedPauseData(void) {
        if (remove("relaxedPauseData.txt") == 0) {
                printf("relaxedPauseData.txt deleted successfully\n");
                return 0;
        } else {
                printf("Error deleting relaxedPauseData.txt\n");
                return 1;
        }
}

int timeRelaxedPause(void) {
        printf("Take a normal inhale, then a normal exhale.\n");
        printf("Hold your breath after the exhale.\n");
        printf("When you feel the first natural urge to breathe, stop. Don’t strain.\n");
        printf("Time this — that’s your Relaxed Pause.\n\n");
        printf("Measurement starts in 5 seconds\n");
        countdown(5);

        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        time_t start, end;
        int elapsed;

        start = time(NULL);
        printf("Running... Press Enter to stop\n");
        fflush(stdout);

        // Wait for Enter key
        while ((c = getchar()) != '\n' && c != EOF);

        end = time(NULL);
        elapsed = (int)difftime(end, start);

        printf("Elapsed time: %d seconds\n", elapsed);
        return elapsed;
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

int change_by_x_percent(int value, int percent) {
        return value + (value * percent) / 100;
}

int restfulPauseValue(){
        int seconds;

        seconds = read_value();

        if (seconds == 0) {
                seconds = timeRelaxedPause();
                write_value(seconds);
        }
        printf("Seconds is %d in the relaxed pause\n", seconds);
        return seconds;
}

void typeAtraining(void){
        int seconds;

        seconds = restfulPauseValue();

        printf("Pausing for 15 seconds to rest\n");

        sleep(15);

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

void typeBtraining(void){
        printf("Type B Training - Increasing Breath Hold, Fixed Rest\n");

        int seconds = restfulPauseValue();

        printf("Pausing for 15 seconds to rest\n");

        sleep(15);

        int restTimeSeconds = 20;

        int rounds = 5;

        int percentchange[] = {-30, -15, 0, 15, 30};

        int BreathHoldRoundLengths[rounds];

        for (int i = 0; i < rounds; i++) {
                BreathHoldRoundLengths[i] = change_by_x_percent(seconds, percentchange[i]);
        }

        for (int i = 0; i < rounds; i++) {
                seconds = BreathHoldRoundLengths[i];
                printf("Round: %d\n", i+1);
                printf("Hold exhale\n");
                countdown(seconds);
                printf("Rest\n");
                countdown(restTimeSeconds);
        }
}
void menu(void){
        printf("👉 Pick your training\n");
        printf("-----------------------------------------------\n");
        printf("Default (enter) - Same as last time\n");
        printf("1. Type A - Fixed Breath Hold, Decreasing Rest\n");
        printf("2. Type B - Increasing Breath Hold, Fixed Rest\n");
        printf("3. Delete last relaxed hold data\n");

        int indexSwitch;

        scanf("%d", &indexSwitch);

        switch (indexSwitch) {
                case 1:
                        typeAtraining();
                        break;
                case 2:
                        typeBtraining();
                        break;
                case 3:
                        deleteRelaxedPauseData();
                        menu();
                        break;
                default:
                        printf("placeholder for same as last time");
                        break;
        }
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

        menu();

        return 0;
}
