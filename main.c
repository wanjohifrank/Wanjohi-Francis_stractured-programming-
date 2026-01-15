 #include <stdio.h>
 #define BUFFER_SIZE 5

 typedef struct {
      int data[BUFFER_SIZE];
      int head;
      int count;
 } CircularLogger;

 void initLogger (CircularLogger *log){
       log->head = 0;
       log->count = 0;
 }

 void insertSample(CircularLogger *log, int value){
     log->data[log->head] = value;
     log->head = (log->head + 1) % BUFFER_SIZE;
     if (log->count < BUFFER_SIZE){
        log->count++;
     }
 }

 void printSamles (const CircularLogger *log){
      if (log->count == 0){
        printf("buffer is empty. \n");
        return;
      }
      int start = (log->head - log->count + BUFFER_SIZE) % BUFFER_SIZE;
      printf("strored samples (oldest -> newest): ");
      for (int i = 0; i < log->count; i++){
        int index = (start + 1) % BUFFER_SIZE;
        printf("%d", log->data[index]);
        if (i != log->count - 1){
            printf(" ");
        }
      }
      printf("\n");
 }

 int main (){
       CircularLogger logger;
       initLogger(&logger);

       int choice;
       while (1){
        printf("\n MENU\n");
        printf("1.insert new sample\n");
        printf("2. print stored samples\n");
        printf("3. exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1){
            printf("invalid choice");
            break;
        }
        if (choice == 1){
            int sample;
            printf("Enter value: ");
            if (scanf("%d", &sample) != 1){
                printf("invalid input try again\n");
                while (getchar() !='\n');
                continue;
            }
            insertSample(&logger, sample);
            printf("sample inserted\n");
        }else if (choice == 2){
            printSamles(&logger);
            }
        else if (choice == 3){
        printf("exiting program\n");
        break;
        }else {
         printf(" invalid chooice");
         }
       }
       return 0;
 }
