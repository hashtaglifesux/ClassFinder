#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

int isPast(char class_time[]) {
  // current datetime as "weekday #, HH:MM"
  time_t now;
  struct tm ts;
  time(&now);
  ts = *localtime(&now);
  char ftime[8];
  strftime(ftime, 8, "%w %H:%M", &ts);
  ftime[7] = 0;
  
  // read datetime from schedule in same format
  char classtime_cpy[8];
  memcpy(classtime_cpy, class_time, 7);
  classtime_cpy[7] = 0;
  
  if (strcmp(class_time, ftime) > 0) {
    return 0;
  }
  return 1;
}


int main() {
  char fname[] = "path/to/classsheet.txt";
  struct stat st;
  stat(fname, &st);
  int size = st.st_size;
  
  char* schedule = malloc(size);
  FILE* fptr;
  fptr = fopen(fname, "r");
  fread(schedule, size, 1, fptr);
  
  uint64_t i = 0;
  while (i < size-9) {
    // if the time on the event is in the past, skip to the next event
    if (isPast(schedule+i) ) {
      i = (uint64_t)(strstr(schedule+i, "\n\n") + 2 - schedule);
    }
    // print details of the next event to console and exit
    else {
      i += 7;
      uint64_t j = (uint64_t)(strstr(schedule+i, "\n\n") - schedule);
      char* class_details = malloc(j-i);
      memcpy(class_details, schedule+i, j-i);
      printf("%s\n\n", class_details);
      break;
    }
  }
  
  fclose(fptr);
  return 0;
}
