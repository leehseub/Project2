#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

// 파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    if(stat("text1", &stat1) == -1){
        perror("파일 1 정보 오류");
        return;
    }

    printf("[파일 1의 정보]\n");
    printf("파일 크기: %ld bytes\n", stat1.st_size);
    printf("블록 수: %ld\n", stat1.st_blocks);
    printf("UID: %d, GID: %d\n", stat1.st_uid, stat1.st_gid);
    printf("\n");
}

// 파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    if(stat("text2", &stat2) == -1){
        perror("파일 2 정보 오류");
        return;
    }

    printf("[파일 2의 정보]\n");
    printf("파일 크기: %ld bytes\n", stat2.st_size);
    printf("블록 수: %ld\n", stat2.st_blocks);
    printf("UID: %d, GID: %d\n", stat2.st_uid, stat2.st_gid);
    printf("\n");
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1 = localtime(&stat1.st_mtime); // 월/일, 시/분
    
    printf("[파일 1의 수정 시간]\n");
    printf("수정 날짜: %02d/%02d\n", time1->tm_mon + 1, time1->tm_mday);
    printf("수정 시간: %02d:%02d\n", time1->tm_hour, time1->tm_min);
    printf("\n");
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime); // 월/일, 시/분

    printf("[파일 2의 수정 시간]\n");
    printf("수정 날짜: %02d/%02d\n", time2->tm_mon + 1, time2->tm_mday);
    printf("수정 시간: %02d:%02d\n", time2->tm_hour, time2->tm_min);
    printf("\n");
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}