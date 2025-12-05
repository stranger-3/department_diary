#include <stdio.h>
#include <string.h>

struct Activity {
    char task[50];
    char date[20];
    char time[10];
    char location[30];
};

struct Activity diary[100];
int count = 0;

void addActivity();
void viewActivities();
void editActivity();
void deleteActivity();
void searchActivity();
void todaysActivities();
void saveData();
void loadData();

int main() {
    int choice;
    
    loadData();
    
    printf("=== DEPARTMENT DIARY ===\n");
    
    do {
        printf("\nMAIN MENU:\n");
        printf("1. Add Activity\n");
        printf("2. View All\n");
        printf("3. Edit\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Today's Activities\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1: addActivity(); break;
            case 2: viewActivities(); break;
            case 3: editActivity(); break;
            case 4: deleteActivity(); break;
            case 5: searchActivity(); break;
            case 6: todaysActivities(); break;
            case 7: saveData(); printf("Data saved!\n"); break;
            default: printf("Invalid!\n");
        }
    } while(choice != 7);
    
    return 0;
}

void addActivity() {
    if(count >= 100) {
        printf("Diary is full! Cannot add more activities.\n");
        return;
    }

    printf("\n--- NEW ACTIVITY ---\n");
    
    printf("Task: ");
    fgets(diary[count].task, 50, stdin);
    diary[count].task[strcspn(diary[count].task, "\n")] = 0;
    
    printf("Date (DD/MM/YY): ");
    fgets(diary[count].date, 20, stdin);
    diary[count].date[strcspn(diary[count].date, "\n")] = 0;
    
    printf("Time: ");
    fgets(diary[count].time, 10, stdin);
    diary[count].time[strcspn(diary[count].time, "\n")] = 0;
    
    printf("Location: ");
    fgets(diary[count].location, 30, stdin);
    diary[count].location[strcspn(diary[count].location, "\n")] = 0;
    
    count++;
    printf("Added successfully!\n");
}

void viewActivities() {
    if(count == 0) {
        printf("\nNo activities!\n");
        return;
    }
    
    printf("\n--- ALL ACTIVITIES (%d) ---\n", count);
    printf("No.  %-25s %-10s %-10s %-20s\n", 
           "Task", "Date", "Time", "Location");
    printf("---------------------------------------------------------------------\n");
    
    for(int i = 0; i < count; i++) {
        printf("%-4d %-25.25s %-10s %-10s %-20.20s\n", 
               i+1, 
               diary[i].task, 
               diary[i].date, 
               diary[i].time, 
               diary[i].location);
    }
}

void editActivity() {
    if(count == 0) {
        printf("\nNo activities to edit!\n");
        return;
    }
    
    int num;
    viewActivities();
    
    printf("\nEnter activity number to edit: ");
    scanf("%d", &num);
    getchar();
    
    if(num < 1 || num > count) {
        printf("Invalid number!\n");
        return;
    }
    
    int index = num - 1;
    
    printf("\nEditing activity %d:\n", num);
    printf("New task (current: %s): ", diary[index].task);
    char temp[50];
    fgets(temp, 50, stdin);
    temp[strcspn(temp, "\n")] = 0;
    if(strlen(temp) > 0) strcpy(diary[index].task, temp);
    
    printf("New date: ");
    fgets(diary[index].date, 20, stdin);
    diary[index].date[strcspn(diary[index].date, "\n")] = 0;
    
    printf("New time: ");
    fgets(diary[index].time, 10, stdin);
    diary[index].time[strcspn(diary[index].time, "\n")] = 0;
    
    printf("New location: ");
    fgets(diary[index].location, 30, stdin);
    diary[index].location[strcspn(diary[index].location, "\n")] = 0;
    
    printf("Updated!\n");
}

void deleteActivity() {
    if(count == 0) {
        printf("\nNo activities to delete!\n");
        return;
    }
    
    int num;
    viewActivities();
    
    printf("\nEnter activity number to delete: ");
    scanf("%d", &num);
    getchar();
    
    if(num < 1 || num > count) {
        printf("Invalid number!\n");
        return;
    }
    
    printf("Delete '%s'? (y/n): ", diary[num-1].task);
    char confirm;
    scanf("%c", &confirm);
    
    if(confirm == 'y') {
        for(int i = num-1; i < count-1; i++) {
            diary[i] = diary[i+1];
        }
        count--;
        printf("Deleted!\n");
    } else {
        printf("Cancelled!\n");
    }
}

void searchActivity() {
    if(count == 0) {
        printf("\nNo activities to search!\n");
        return;
    }
    
    char search[50];
    printf("\nSearch by:\n");
    printf("1. Task name\n");
    printf("2. Date\n");
    printf("3. Location\n");
    printf("Choice: ");
    
    int choice;
    scanf("%d", &choice);
    getchar();
    
    printf("Enter search text: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = 0;
    
    printf("\nSearch Results:\n");
    printf("-------------------------------------------------\n");
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        int match = 0;
        
        switch(choice) {
            case 1: 
                if(strstr(diary[i].task, search) != NULL) match = 1;
                break;
            case 2: 
                if(strcmp(diary[i].date, search) == 0) match = 1;
                break;
            case 3: 
                if(strstr(diary[i].location, search) != NULL) match = 1;
                break;
        }
        
        if(match) {
            printf("%d. %s on %s at %s (%s)\n", 
                   i+1, diary[i].task, diary[i].date, 
                   diary[i].time, diary[i].location);
            found++;
        }
    }
    
    if(found == 0) {
        printf("No matches found!\n");
    } else {
        printf("Found %d activities\n", found);
    }
}

void todaysActivities() {
    char today[20];
    printf("\nEnter today's date (DD/MM/YY): ");
    fgets(today, 20, stdin);
    today[strcspn(today, "\n")] = 0;
    
    printf("\n=== TODAY'S ACTIVITIES (%s) ===\n", today);
    printf("-------------------------------------------------\n");
    
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(diary[i].date, today) == 0) {
            printf("* %s at %s in %s\n", 
                   diary[i].task, diary[i].time, diary[i].location);
            found++;
        }
    }
    
    if(found == 0) {
        printf("No activities today!\n");
    } else {
        printf("\nTotal: %d activity(s) today\n", found);
    }
}

void saveData() {
    FILE *file = fopen("diary.txt", "w");
    
    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%s\n", 
                diary[i].task,
                diary[i].date,
                diary[i].time,
                diary[i].location);
    }
    
    fclose(file);
}

void loadData() {
    FILE *file = fopen("diary.txt", "r");
    if(file == NULL) return;
    
    char line[150];
    while(fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        
        char *token = strtok(line, ",");
        if(token) strcpy(diary[count].task, token);
        
        token = strtok(NULL, ",");
        if(token) strcpy(diary[count].date, token);
        
        token = strtok(NULL, ",");
        if(token) strcpy(diary[count].time, token);
        
        token = strtok(NULL, ",");
        if(token) strcpy(diary[count].location, token);
        
        count++;
    }
    
    fclose(file);
}