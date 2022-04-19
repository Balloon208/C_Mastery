#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    int eng[101][100] = {}, kor[101][100] = {}, word[100] = {}, right = 0, fail = 0;
    int n, chs, rdm = 0;
    printf("Input the number of words : ");
    scanf("%d", &n);
    printf("Input the words, ex)Apple 사과[Enter]\n");
    printf("But do not enter spaces within words\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", eng[i]);
        scanf("%s", kor[i]);
    }
    printf("Choose among the two ways, (1: kor->eng), (2: eng->kor) : ");
    scanf("%d", &chs);
    if (chs == 1) {
        while (1) {
            rdm = rand() % n;
            printf("%s : ", kor[rdm]);
            scanf("%s", word);
            if (!(strcmp(word, "QUIT"))) break;
            if (!(strcmp(eng[rdm], word)))
            {
                printf("correct!\n");
                right++;
            }
            else
            {
                printf("wrong : %s\n", eng[rdm]);
                fail++;
            }
        }
    }
    else if (chs == 2) {
        while (1) {
            rdm = rand() % n;
            printf("%s : ", eng[rdm]);
            scanf("%s", word);
            if (!(strcmp(word, "QUIT"))) break;
            if (!(strcmp(kor[rdm], word))) {
                printf("correct!\n");
                right++;
            }
            else {
                printf("wrong : %s\n", kor[rdm]);
                fail++;
            }
        }
    }
    printf("\n결과\n\n푼 갯수 : %d\n정답 : %d\n오답 : %d\n정답률 : %.2lf%%\n", fail + right, right, fail, fail == 0 ? 100.00 : (float)(right * 100) / (right + fail));
    printf("아무키나 눌러서 종료");
    getch();
    return 0;
}
