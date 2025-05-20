#include <stdio.h>
#include <unistd.h>   // Sleep
#include <time.h>     // Timer
#include <stdbool.h>  // Bool

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

int timerRelaxedPause(void) {
        printf("----------------------------\n");
        printf("Take a normal inhale, then a normal exhale.\n");
        printf("Hold your breath after the exhale.\n");
        printf("When you feel the first natural urge to breathe, stop. Don’t strain.\n");
        printf("Time this — that’s your Relaxed Pause.\n\n");
        printf("Measurement starts in 5 seconds\n");
        countdown(5);

        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        time_t startTime, currentTime;
        int elapsedSeconds;
        int lastDisplayedSeconds = -1; // Not sure why I did this. Review later.

        startTime = time(NULL);
        printf("Running... Press Enter to stop\n");
        fflush(stdout);

        // Wait for Enter key and display elapsed time
        while ((c = getchar()) != '\n' && c != EOF) {
                currentTime = time(NULL);
                elapsedSeconds = (int)difftime(currentTime, startTime);
                if (elapsedSeconds != lastDisplayedSeconds) { // Update when seconds change
                printf("\r%03d", elapsedSeconds); // 3-digit padded time
                fflush(stdout); // immediate display
                lastDisplayedSeconds = elapsedSeconds;
                }
        }

        currentTime = time(NULL);
        elapsedSeconds = (int)difftime(currentTime, startTime);

        printf("\rElapsed time: %d seconds\n", elapsedSeconds);
        return elapsedSeconds;
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
        int holdSeconds;

        holdSeconds = read_value();


        if (holdSeconds == 0) {
                holdSeconds = timerRelaxedPause();
                write_value(holdSeconds);
        }
        printf("holdSeconds is %d in the relaxed pause\n", holdSeconds);
        return holdSeconds;
}

void typeAtraining(void){
        int holdSeconds;

        holdSeconds = restfulPauseValue();

        printf("Pausing for 15 seconds to rest\n");

        sleep(15);

        int restsec = 60;
        int rounds = 5;

        printf("Exhale\n");
        sleep(5);

        bool keepGoing = true;
        while (keepGoing) {
                for (int i = 0; i < rounds; i++) {
                        printf("Round: %d\n", i+1);
                        printf("Hold exhale\n");
                        countdown(holdSeconds);
                        printf("Rest\n");
                        countdown(restsec);
                        restsec -= 10;
                }
                printf("Continue? (Enter twice to continue, Enter + 'n' to stop): ");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
                ch = getchar();
                if (ch == 'n' || ch == 'N') {
                        keepGoing = false;
                }
        }
        printf("Done! returning to menu\n");
        menutext();
        menulogic();
}

void typeBtraining(void){
        printf("Type B Training - Increasing Breath Hold, Fixed Rest\n");

        int holdSeconds = restfulPauseValue();

        printf("Pausing for 15 seconds to rest\n");

        sleep(15);

        int restTimeSeconds = 20;

        int rounds = 5;

        int percentchange[] = {-30, -15, 0, 15, 30};

        int BreathHoldRoundLengths[rounds];

        for (int i = 0; i < rounds; i++) {
                BreathHoldRoundLengths[i] = change_by_x_percent(holdSeconds, percentchange[i]);
        }
        bool keepGoing = true;
        while (keepGoing) {
                for (int i = 0; i < rounds; i++) {
                        holdSeconds = BreathHoldRoundLengths[i];
                        printf("Round: %d\n", i + 1);
                        printf("Hold exhale\n");
                        countdown(holdSeconds);
                        printf("Rest\n");
                        countdown(restTimeSeconds);
                }
                printf("Continue? (Enter twice to continue, Enter + 'n' to stop): ");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
                ch = getchar();
                if (ch == 'n' || ch == 'N') {
                        keepGoing = false;
                }
        }
        printf("Done! returning to menu\n");
        menutext();
        menulogic();
}

void typeCtraining(void){
        printf("Tidal Breath \n");
        printf("Fixed Breath Hold, Fixed Rest, Infinite Loop\n");
        printf("----------------------------\n");
        printf("No prep needed.\n"
               "Inhale slowly through nose or mouth, normal breath only.\n"
               "Breathe from diaphragm if possible.\n"
               "Pause 1 second after inhale, then exhale normally.\n"
               "Stop exhaling at neutral point, don’t overexhale.\n"
               "Pause breath for ~10 seconds (adjust based on comfort).\n"
               "Repeat as long as you can.\n");

        int holdSeconds = 10;

        printf("Pausing for 5 seconds to prepare\n");

        sleep(5);

        int restsec = 5;
        int rounds = 5;

        printf("Exhale\n");
        countdown(restsec);

        bool keepGoing = true;
        while (keepGoing) {
                for (int i = 0; i < rounds; i++) {
                        printf("Round: %d\n", i+1);
                        printf("Hold exhale\n");
                        countdown(holdSeconds);
                        printf( "Inhale slowly through nose or mouth, normal breath only.\n");
                        countdown(restsec);
                        printf("Pause 1 second, then exhale normally.\n");
                        printf("Stop exhaling at neutral point.\n");
                        countdown(restsec);
                }
                printf("Continue? (Enter twice to continue, Enter + 'n' to stop): ");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
                ch = getchar();
                if (ch == 'n' || ch == 'N') {
                        keepGoing = false;
                }
        }

        printf("Done! returning to menu\n");
        menutext();
        menulogic();

}

void menutext(void){
        printf("👉 Pick your training\n");
        printf("-----------------------------------------------\n");
        printf("Default (enter) - Same as last time\n");
        printf("0. Delete last relaxed hold data\n");
        printf("1. Type A - Fixed Breath Hold, Decreasing Rest\n");
        printf("2. Type B - Increasing Breath Hold, Fixed Rest\n");
        printf("3. Type C - Fixed Breath Hold, Fixed Rest, Infinite Loop\n");
}

void menulogic(void){

        int indexSwitch;

        scanf("%d", &indexSwitch);

        switch (indexSwitch) {
                case 0:
                        deleteRelaxedPauseData();
                        printf("Pick again:");
                        menulogic();
                        break;
                case 1:
                        typeAtraining();
                        break;
                case 2:
                        typeBtraining();
                        break;
                case 3:
                        typeCtraining();
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
        printf("-------------------------------Leverages----------------\n");
        printf("CO2 tolerance is like a thermostat for breathing:\n");
        printf(" - Low CO2 tolerance = hypersensitive thermostat = fast breathing = airway collapse\n");
        printf(" - High CO2 tolerance = steady thermostat = slow, calm breathing = open airway\n");

        menutext();
        menulogic();

        return 0;
}
