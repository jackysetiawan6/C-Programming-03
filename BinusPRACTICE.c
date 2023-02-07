#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void prob1A(), prob1B(), prob1C(), prob1D(), prob1E(), prob1F(), prob1G(), prob1H(), prob1I(), prob1J();

void prob1K(), prob1L(), prob1M(), prob1N(), prob1O(), prob1P(), prob1Q(), prob1R(), prob1S(), prob1T();

void prob1U(), prob1V(), prob1W();

void prob2A(), prob2B(), prob2C();

int main() { prob2A(); return 0; }

void prob1A()
{
    int input, last = 0, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int temp; scanf("%d", &temp); last += temp;

        last = last == 9 ? 21 : last == 33 ? 42 : last == 76 ? 92 :
               last == 53 ? 37 : last == 80 ? 59 : last == 97 ? 88 :
               last;
    }
    printf("%d\n", last);
}

void prob1B()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int need, stock, market;
        
        scanf("%d %d %d", &need, &stock, &market); getchar();

        printf("Case #%d: %s\n", i, need <= stock + market ? "yes" : "no");
    }
}

void prob1C()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int male, female; scanf("%d %d", &male, &female); getchar();

        int status = !(male % 2) || !(female % 2);

        printf("Case #%d: %s\n", i, status ? "Party time!" : "Need more frogs");
    }
}

void prob1D()
{
    int start, length, i; scanf("%d %d", &start, &length); getchar();

    for (i = start; i <= start + length; i++) printf("%d\n", i);
}

void prob1E()
{
    int a, b, c, d;
	
	scanf("%d %d %d %d", &a, &b, &c, &d); getchar();
	
	printf((long long int)(a * b) == c - d ? "True\n" : "False\n");
}

void prob1F()
{
    int input, i; scanf("%d", &input); getchar();

    long long int sum = 0;

    for (i = 1; i <= input; i++)
    {
        long long int value; scanf("%lld", &value); getchar();

        sum = sum + value <= sum ? sum : sum + value;
    }
    printf("%lld\n", sum);
}

void prob1G()
{
    char first, second; scanf("%c %c", &first, &second);

    long long int result = (int)first * (int)second;

    printf("%lld\n", result);
}

void prob1H()
{
    int input, i, j; scanf("%d", &input); getchar();

    for (i = 1; i<= input; i++)
    {
        int length; long long int addition;
        
        scanf("%d %lld", &length, &addition); getchar();

        char string[length]; gets(string);

        for (j = 0; j < length; j++)
        {
            addition -= (26 * (addition / 26));

            string[j] = ((string[j] - 97 + addition) % 26) + 97;
        }
        printf("Case #%d: %s\n", i, string);
    }
}

void prob1I()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        long long int money, discount, cashback, result = 0;

        scanf("%lld %lld %lld", &money, &discount, &cashback); getchar();

        result = (money * discount / 100);

        printf("Case #%d: %lld\n", i, result >= cashback ? cashback : result);
    }
}

void prob1J()
{
    int input, i, j; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int number; scanf("%d", &number); getchar();

        long long int value, result = 0;

        for (j = 1; j <= number; j++)
        {
            scanf("%lld", &value); result += value;
        }
        printf("Case #%d: %lld\n", i, result);
    }
}

void prob1K()
{
    int input, i, j; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int number; scanf("%d", &number); getchar(); int values[number];

        for (j = 0; j < number; j++) scanf("%d", &values[j]);

        long long int prefix[number], suffix[number]; int status = 0;

        prefix[0] = values[0]; suffix[number - 1] = values[number - 1];

        for (j = 1; j < number; j++)
        {
            prefix[j] = prefix[j - 1] + values[j];

            suffix[number - 2] = suffix[number - 1] + values[number - 2];
        }
        for (j = 0; j < number - 1; j++)
        {
            if (prefix[j] == suffix[j + 1]) { status = 1; break; }
        }
        printf("Case #%d: %s\n", i, status ? "Yes" : "No");
    }
}

void prob1L()
{
    int input, i, result = 0; scanf("%d", &input);

    for (i = 1; i <= input; i++)
    {
        int temp; scanf("%d", &temp); result += temp;
    }
    printf("%d\n", result);
}

void prob1M()
{
    int input, i, j; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int total, a, b, c, d, result = 0;
        
        scanf("%d %d %d %d %d", &total, &a, &b, &c, &d); getchar();

        for (j = 1; j <= total; j++)
        {
            result += !(j % a) || !(j % b) || !(j % c) || !(j % d) ? 1 : 0;
        }
        printf("Case #%d: %d\n", i, result);
    }
}

void prob1N()
{
    int input; scanf("%d", &input); getchar();

    printf("%lld\n", (1 << input) - 1);
}

void prob1O()
{
    int input; scanf("%d", &input); getchar();

    printf("%lld\n", (100 * input) + (50 * input * (input - 1) / 2));
}

void prob1P()
{
    int input, i, j; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        int length; scanf("%d", &length); getchar();

        char string[length]; gets(string);

        printf("Case #%d: ", i);

        for (j = 0; j < length; j++)
        {
            isalpha(string[j]) ? printf("%c", string[j]) : printf("");
        }
        printf("\n");
    }
}

void prob1Q()
{
    int loop, size, i, j; scanf("%d %d", &loop, &size); getchar();
    
    while (loop-- > 0)
    {
        for (i = 1; i <= size; i++)
        {
            for (j = 1; j <= size; j++) printf("%c", j <= size - i ? ' ' : '*');

            printf("\n");
        }
    }
}

void prob1R()
{
    double first, second, floor;
    
    scanf("%lf %lf %lf", &first, &second, &floor); getchar();

    printf("%d\n", (first + second) / 2 == floor ? 1 : -1);
}

void prob1S()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        double a, b, c, d;
        
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d); getchar();

        printf("%.2lf\n", (2 * (a + b)) + (4 * c / 3) + (d / 2));
    }
}

void prob1T()
{
    int input = 5, i;

    for (i = 1; i <= input; i++)
    {
        char string[11]; int hour1, minute1, hour2, minute2;

        scanf("%s %d:%d-%d:%d", string, &hour1, &minute1, &hour2, &minute2);

        printf("%s %02d:%02d-%02d:%02d\n", string, hour1 - 1, minute1, hour2 - 1, minute2);
    }
}

void prob1U()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        double degree; long long int number;
        
        scanf("%lf %lld", &degree, &number); getchar();

        printf("%.2lf\n", degree / 360 * number);
    }
}

void prob1V()
{
    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        double number; scanf("%lf", &number); getchar();

        double R = 4 * number / 5, F = (9 * number / 5) + 32;

        printf("%.2lf %.2lf %.2lf\n", R, F, number + 273);
    }
}

void prob1W()
{
    int input = 3, i;

    for (i = 1; i <= input; i++)
    {
        char number[4]; gets(number);

        printf("%c\n", number[1]);
    }
}

void prob2A()
{
    struct data { char ID[100], name[100], major[100], pos[100]; double IPK; } datas[1000];

    int input, i; scanf("%d", &input); getchar();

    for (i = 1; i <= input; i++)
    {
        gets(datas[i].ID); gets(datas[i].name); gets(datas[i].major);
        
        scanf("%lf", &datas[i].IPK); getchar(); gets(datas[i].pos);
    }
    //searching major with pos
}

void prob2B()
{
    //s
}