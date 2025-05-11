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
void sizecmp(struct stat* buf1, struct stat* buf2);
void blockcmp(struct stat* buf1, struct stat* buf2);
void datecmp();
void timecmp();

int main()
{
    struct stat stat1, stat2;

    struct stat* buf1 = &stat1;
    struct stat* buf2 = &stat2;

    stat("text1", buf1);
    stat("text2", buf2);

    //filestat1();
    //filestat2();
    // filetime1();
    // filetime2();
    sizecmp(buf1, buf2);
    blockcmp(buf1, buf2);
    // datecmp();
    // timecmp();
   
    return 0;
}

// 파일 1의 정보를 가져오는 함수 작성
void filestat1(){

    // 파일 크기: stat.st_size
    // 블록 수: stat.st_blocks
    // UID: stat.st_uid
    // GID: stat.st_gid

    if(stat("text1", &stat1) == -1){
        perror("파일 1 정보 오류");
        return;
    }
}

// 파일 2의 정보를 가져오는 함수 작성
void filestat2(){

    // 파일 크기: stat.st_size
    // 블록 수: stat.st_blocks
    // UID: stat.st_uid
    // GID: stat.st_gid

    if(stat("text2", &stat2) == -1){
        perror("파일 2 정보 오류");
        return;
    }
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    //time_t -> tm 구조체로 변환
    time1 = localtime(&stat1.st_mtime);
    //변환 실패 시 에러 출력      
    if(!time1){
        fprintf(stderr,"ERROR : Failed to get time1\n");
    }
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    //time_t -> tm 구조체로 변환
    time2 = localtime(&stat2.st_mtime);
    //변환 실패 시 에러 출력
    if(!time2){
        fprintf(stderr,"ERROR : Failed to get time2\n");
    }
}
*/

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(struct stat* buf1, struct stat* buf2)
{
    printf("size compare\n");

    if (buf1->st_size > buf2->st_size)
	    printf("text1 is bigger\n\n");
    else if (buf1 -> st_size == buf2 -> st_size)
	    printf("sizes are equal\n\n");
    else
	    printf("text2 is bigger\n\n");

}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(struct stat* buf1, struct stat* buf2)
{
    printf("block compare\n");

    if (buf1->st_blocks > buf2->st_blocks)
            printf("text1 is bigger\n\n");
    else if (buf1 -> st_blocks == buf2 -> st_blocks)
            printf("sizes are equal\n\n");
    else
            printf("text2 is bigger\n\n");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}

