#include "calenderprint.h"

int calenderprint(void)
{
    int yyyy, mm;
    printf("연도를 입력하십시오: ");
    scanf("%d", &yyyy);
    printf("월을 입력하십시오: ");
    scanf("%d", &mm);

    printf("\n          %d년 %d월\n", yyyy, mm);// year년 month월 타이틀 출력

    int start_day = get_day(yyyy, mm);
    int day_num = get_day_of_month(yyyy, mm);
    print_cal(start_day, day_num);
}
void print_cal(int start_day, int day_num)
{
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < start_day; i++)
        printf("    ");
    for (int day = 1, ke = start_day; day <= day_num; day++, ke++)
    {
        printf("%4d", day);
        if (ke % 7 == 6)
            printf("\n");
    }
}
int get_day(int yyyy, int mm)
{
    int past = 0;
    for (int y = 1; y < yyyy; y++)
        past = past + 365 + is_leaf_year(y);
    for (int m = 1; m < mm; m++)
        past = past + get_day_of_month(yyyy, m);
    return (1 + past) % 7;
}
int get_day_of_month(int yyyy, int mm) //달의 총 날짜수
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    day_of_month[2] += is_leaf_year(yyyy);
    return day_of_month[mm];
}
int is_leaf_year(int yyyy) //윤년
{
    if (yyyy % 400 == 0)
        return 1;
    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;
    return 0;
}