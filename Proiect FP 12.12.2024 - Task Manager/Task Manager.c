//Panait Claudia-Alexandra, Info 1, grupa 3 - 12/12/2024
//Proiect Task Manager - FP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //inspiratie navigating
#include "Color_palette.h" //inspiratie curs precedent
#define MAX_TASKS 100 //inspiratie curs de mai demult
#define MAX_STRING 256
#define FILENAME "tasks.txt" //inspiratie navigating

typedef enum { //inspiratie curs precedent
    low = 1, medium, high
} priority;

typedef struct {
    int dd,mm,yyyy;
} date;

typedef struct {
    char name[MAX_STRING];
    char description[MAX_STRING];
    date deadline;
    priority priority;
} task;

task tasks[MAX_TASKS];
int tasksCount = 0; // forgiveness

int validateDate(date date) {
    time_t t = time(NULL);
    struct tm* currentTime = localtime(&t); //inspiratie navigating

    if (date.yyyy < currentTime->tm_year + 1900) { //campul tm_year  reprezinta nr de ani trecuți de la 1900
        printf("%sInvalid year! Please re-enter the date!%s\n", BRIGHT_RED, RESET);
        return 0; }

    if (date.mm < 1 || date.mm > 12) {
        printf("%sInvalid month! Please re-enter the date!%s\n", BRIGHT_RED, RESET);
        return 0; }

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//in general
    if (date.yyyy % 4 == 0) monthDays[1] = 29; //cazul anului bisect

    if (date.yyyy == currentTime->tm_year + 1900) {
        if (date.mm < currentTime->tm_mon + 1) {
            printf("%sInvalid month! Please re-enter the date!%s\n", BRIGHT_RED, RESET);
            return 0; }
        if (date.mm == currentTime->tm_mon + 1 && date.dd < currentTime->tm_mday) {
            printf("%sInvalid day! Please re-enter the date!%s\n", BRIGHT_RED, RESET);
            return 0; }
    }
    if (date.dd < 1 || date.dd > monthDays[date.mm - 1]) {
        printf("%sInvalid day! Please re-enter the date!%s\n", BRIGHT_RED, RESET);
        return 0; }
    return 1;
}

const char* priorityToString(priority p) {
    switch(p) {
        case low: return "Low";
        case medium: return "Medium";
        case high: return "High";
        default: return "Unspecified"; }
}

void saveTasks() {
    FILE* f = fopen(FILENAME, "w"); //inspiratie navigating: f = pointer de tip FILE
    //care refera fisierul prin functia fopen si modul w de deschidere
    if (f == NULL) {
        printf("%sError! Unable to open the file!%s\n", BG_BRIGHT_RED, RESET);
        return; }
    for (int i = 0; i < tasksCount; i++) {
        fprintf(f, "%s\n%s\n%d %d %d\n%d\n",
                tasks[i].name,              tasks[i].description,
                tasks[i].deadline.dd,       tasks[i].deadline.mm,
                tasks[i].deadline.yyyy,     tasks[i].priority);      }
    fclose(f);
}

void loadTasks() {
    FILE* f = fopen(FILENAME, "r"); //modul r deschide fisierul pentru citire
    if (f == NULL) return; // f nu refera un fisier valid - deschidere esuata

    tasksCount = 0;
    // feof(f) apartine librariei standard C
    //         verifica daca este END OF FILE
    //         returneaza 1 daca f este sfarsit, 0 in caz contrar
    while (!feof(f) && tasksCount < MAX_TASKS) {
        task t;
        if (fgets(t.name, MAX_STRING, f)) {
            t.name[strcspn(t.name, "\n")] = 0; // t.name[lungimea pana la primul \n] si inlocuim \n cu \0
            if (fgets(t.description, MAX_STRING, f)) {
                t.description[strcspn(t.description, "\n")] = 0;// idem
                fscanf(f, "%d %d %d\n", &t.deadline.dd,
                       &t.deadline.mm,  &t.deadline.yyyy);
                fscanf(f, "%d\n", (int*)&t.priority);
                tasks[tasksCount++] = t;
            }
        }
    }
    fclose(f);
}

void addTask() {
    if (tasksCount >= MAX_TASKS) {
        printf("%sTask list has reached its maximum capacity!%s\n", BG_BRIGHT_RED, RESET);
        return;
    }
    task t;
    printf("%sEnter the task name:%s ", VERY_LIGHT_PINK, RESET);
    fgets(t.name, MAX_STRING, stdin);
    t.name[strcspn(t.name, "\n")] = 0;

    printf("%sEnter the task description:%s ", VERY_LIGHT_PINK, RESET);
    fgets(t.description, MAX_STRING, stdin);
    t.description[strcspn(t.description, "\n")] = 0;

    do {
        printf("%sEnter the deadline (dd mm yyyy):%s ", VERY_LIGHT_PINK, RESET);
        scanf("%d %d %d", &t.deadline.dd, &t.deadline.mm, &t.deadline.yyyy);
        getchar();
    } while (!validateDate(t.deadline));

    do {
        printf("%sEnter the task priority:%s\n", VERY_LIGHT_PINK, RESET);
        printf("%s1-Low%s\n", BRIGHT_GREEN, RESET);
        printf("%s2-Medium%s\n", BRIGHT_YELLOW, RESET);
        printf("%s3-High%s\n", BRIGHT_RED, RESET);
        printf("%sChosen priority:%s ", VERY_LIGHT_PINK, RESET);
        scanf("%d", (int*)&t.priority);
        getchar();
    } while (t.priority < low || t.priority > high);

    tasks[tasksCount++] = t;
    saveTasks();
    printf("%sTask added successfully!%s\n", VERY_LIGHT_PINK, RESET);
}

void showTasks() {
    if (tasksCount == 0) {
        printf("%sNo tasks available!%s\n", BG_BRIGHT_RED, RESET);
        return;
    }

    printf("\n%sTask List:%s\n", PINK1, RESET);
    printf("----------------\n\n");
    for (int i = 0; i < tasksCount; i++) {
        printf("%sTask #%s", PINK1, RESET);
        printf("%d\n", i+1);
        printf("%sName: %s", PINK1, RESET);
        printf("%s\n", tasks[i].name);
        printf("%sDescription: %s", PINK1, RESET);
        printf("%s\n", tasks[i].description);
        printf("%sDeadline:%s ", PINK1, RESET);
        printf("%02d/%02d/%d\n",      tasks[i].deadline.dd,
               tasks[i].deadline.mm,  tasks[i].deadline.yyyy);
        printf("%sPriority:%s ", PINK1, RESET);
        printf("%s\n", priorityToString(tasks[i].priority));
        printf("%s----------------%s\n\n", PINK1, RESET);
    }
}

void deleteTask() {
    char name[MAX_STRING];
    printf("%sEnter the name of the task you want to delete:%s ", BRIGHT_RED, RESET);
    fgets(name, MAX_STRING, stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < tasksCount; i++) {
        if (strcmp(tasks[i].name, name) == 0) { //name found so delete it
            for (int j = i; j < tasksCount - 1; j++) //incepand cu pozitia i mutam toate elementele la stanga
                tasks[j] = tasks[j + 1];
            tasksCount--;
            found = 1;
            break;
        }
    }

    if (found) {
        saveTasks();
        printf("%sTask deleted successfully!%s\n",ORANGE,RESET);
    } else printf("%sTask not found!%s\n",ORANGE,RESET);
}

void editTask() {
    char name[MAX_STRING];
    printf("%sEnter the name of the task you want to edit:%s ",PINK1, RESET);
    fgets(name, MAX_STRING, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < tasksCount; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("%sEnter new details:%s\n",PINK1, RESET);
            printf("%sEnter new name or press enter to keep the current name:%s ",PINK1, RESET);
            char temp[MAX_STRING];  //new name
            fgets(temp, MAX_STRING, stdin);
            temp[strcspn(temp, "\n")] = 0;
            if (strlen(temp) > 0) //valid
                strcpy(tasks[i].name, temp);

            printf("%sEnter new description or press enter to keep the current description:%s ",PINK1, RESET);
            fgets(temp, MAX_STRING, stdin);
            temp[strcspn(temp, "\n")] = 0;
            if (strlen(temp) > 0)
                strcpy(tasks[i].description, temp);

            printf("%sChange deadline? (1 for yes, 0 for no):%s ",PINK1, RESET);
            int change;
            scanf("%d", &change);
            getchar();
            if (change)
                do {
                    printf("%sEnter deadline (dd mm yyyy):%s ",PINK1, RESET);
                    scanf("%d %d %d",            &tasks[i].deadline.dd,
                          &tasks[i].deadline.mm, &tasks[i].deadline.yyyy);
                    getchar();
                } while (!validateDate(tasks[i].deadline));

            printf("%sChange priority? (1 for yes, 0 for no):%s ",PINK1, RESET);
            scanf("%d", &change);
            getchar();
            if (change)
                do {
                    printf("%sPriority (1-Low, 2-Medium, 3-High):%s ",PINK1, RESET);
                    scanf("%d", (int*)&tasks[i].priority);
                    getchar();
                } while (tasks[i].priority < low || tasks[i].priority > high);

            saveTasks();
            printf("%sTask edited successfully!%s\n",PINK1, RESET);
            return;
        }
    }
    printf("%sTask not found!%s\n",ORANGE, RESET);
}
int main() {
    loadTasks();
    while (1) {
        printf("\n%s%s        Menu:        %s\n", BLACK, BG_PINK1, RESET);
        printf("%s1) Add task%s\n", PINK1, RESET);
        printf("%s2) Show task list%s\n", PINK1, RESET);
        printf("%s3) Delete task%s\n", PINK1, RESET);
        printf("%s4) Edit task%s\n", PINK1, RESET);
        printf("%s5) Exit program%s\n", BRIGHT_RED, RESET);
        printf("\n%s  Choose an option:  %s ", BLACK_ON_PINK, RESET);
        int option;
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: deleteTask(); break;
            case 4: editTask(); break;
            case 5: printf("Program terminated!\n",BRIGHT_RED, RESET); return 0;
            default: printf("%sInvalid option!%s\n",ORANGE, RESET); }
    }
    return 0;
}
