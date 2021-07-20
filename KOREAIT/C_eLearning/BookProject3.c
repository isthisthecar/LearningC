#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct book
{
    char bookTitle[50];
    char bookAuthor[50];
    int bookPrice;
    int bookSale;
    char bookcode[8];
}BOOK;
BOOK* inBook(BOOK* , int*);
void outBook{BOOK* , int);
void searchBook(BOOK* ,int);


int main(){
    int sel, totalBCnt=0;
    BOOK *myBook;
    myBook = (BOOK *)calloc(2,sizeof(book));
    while (1){
        puts("\n\n원하는 메뉴를 선택하세요");
        puts("1. 도서입력");
        puts("2. 도서출력");
        puts("3. 도서검색");
        puts("0. 종료");
        scanf("%d",&sel);
        switch (sel){
        case 1 : mybook = inBook(myBook, &totalBCnt);
            break;
        case 2 : outBook(myBook, totalBCnt);
            break;
        case 3 : searchBook(myBook, totalBCnt);
            break;
        case 0 :
            return 0;
        default : puts("0~3 사이에 메뉴 번호를 선택하세요");
        }
    }
    return 0;

}

BOOK* inBook(BOOK* mb, int* cn){
    char yn;
    int cnt;
    cnt = *cn;
    do{
        while (1){
            mb = (BOOK *)realloc(mb,sizeof(BOOK)*(cnt+2));
            fflush(stdin);
            printf("\n책코드 : ");
            gets(mb[cnt].bookCode);
            if (!strcspn(mb[cnt].bookCOde, "0123456789-"))
                break;
            printf("\n책코드를 다시 확인 하세요  형식 : xxxx - xxx");
        }
        printf("책 제목 : ");
        gets(mb[cnt].bookTitle);
        printf("저자 : ");
        gets(mb[cnt].bookAuthor);
        printf("가격 : ");
        scanf("%d",&mb[cnt].bookPrice);
        printf("판매수량 : ");
        gets(mb[cnt].bookTitle);
        printf("\n 계속 입력하시겠습니까? (Y/N)");
        yn = getche();
        cnt++;
    }while (yn == 'y');
    *cn = cnt;
    return mb;
}

int compare(const void *a, const void *b){
    BOOK* ptr_a = (BOOK *)a;
    BOOK* ptr_b = (BOOK *)b;

    if (ptr_a -> bookSale < ptr_b -> bookSale) return 1;
    else if (ptr_a -> booksale == ptr_b -> bookSale) return 0;
    else return -1;
}

void outBook(BOOK* mb, int cnt){
    char sKey[20];
    int i, op;
    char *year;
    int check=0;
    char bestSeller[3][50];
    char yn;
    do{
        puts("\n\n원하는 메뉴를 선택하세요");
        puts("1. 전체출력 ");
        puts("2. 년도별출력 ");
        puts("3. 베스트셀러 ");
        scanf("%d", &op);
        fflush(stdin);
        switch (op){
        case 1 : for (i = 0; i < cnt; i++){
            printf("\n----------------------------------------");
            printf("\n코    드 : %s \n",mb[i].bookCode);
            printf("제   목: %s \n",mb[i].bookTitle);
            printf("저   자 : %s \n",mb[i].bookAuthor);
            printf("가   격: %s \n",mb[i].bookPrice;
            printf("판매수량 : %s \n",mb[i].bookSale);
            }
        
            break;
        
        case 2 : 
                printf("\n\n검색할 출판년도를 입력하세요 : ");
                gets(skey);

                printf("\n----------------------------------------");
                    printf("\n%10s %30s\n", "코   드", "제   목");
                for ( i = 0; i < cnt; i++)
                {
                    year = strtok(mb[i].bookCode,"-");

                    if (!strcmp(year,skey))
                    {
                        printf("\n%10s %30s",mb[i].bookCode, mb[i].bookTitel);
                        check++;
                    }
                    if (check == 0)
                    {
                        printf("\n일치하는 책이 없습니다. \n");
                    }
                    braek;
                }
        case 3 : qsort(mb, cnt+1, sizeof(BOOK), compare);
                 printf("\n----------------------------------\n");
                 printf("----------BestSeller TOP3----------");
                 printf("\n----------------------------------\n");
                 for ( i = 0; i < 3; i++)
                 {
                     printf("TOP %d : %30s Sale: %d\n", i+1, mb[i].bookTitle);
                 }

                 printf("\n----------------------------------\n");
                 break;
                
        }
    }
}