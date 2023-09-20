#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//UTC PROBLEM A
void UTCprobA()
{
    int input, i, j, k, l, m; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++)
    {
        int sizeA, sizeB; scanf("%d %d", &sizeA, &sizeB); getchar();
        int sizeC = sizeA - sizeB + 1;
        long long int arrayA[105][105], arrayB[105][105];
        for (j = 0; j < sizeA; j++)
        {
            for (k = 0; k < sizeA; k++) scanf("%lld", &arrayA[j][k]);
        }
        for (j = 0; j < sizeB; j++)
        {
            for (k = 0; k < sizeB; k++) scanf("%lld", &arrayB[j][k]);
        }
        for (j = 0; j < sizeC; j++)
        {
            for (k = 0;  k < sizeC; k++)
            {
                long long int result = 0;
                for (l = j; l < sizeB + j; l++)
                {
                    for (m = k; m < sizeB + k; m++) result += arrayA[l][m] * arrayB[l - j][m - k];
                }
                printf("%lld%s", result, k == sizeC - 1 ? "\n" : " ");
            }
        }
    }
}

//UTC PROBLEM B
void UTCprobB()
{
    char input[1005]; gets(input);
    int length = strlen(input), alphabet[26], result = 0;
    memset(alphabet, 0, sizeof(alphabet));
    for (int i = 0; i < length; i++)
    {
        if (alphabet[input[i] - 97] == 0)
        {
            alphabet[input[i] - 97] = 1; result++;
        }
    }
    for (int i = 2; i < length; i++)
    {
        for (int j = 0; j < length - i + 1; j++)
        {
            int left = j, right = j + i, status = 1;
            while (left < right)
            {
                if (input[left++] != input[right--])
                {
                    status = 0; break;
                }
            }
            if (status) result++;
        }
    }
    printf("%d\n", result);
}

//UTC PROBLEM C
void UTCprobC()
{
    int input, i, j; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++)
    {
        long long int money, interest, month;
        scanf("%lld %lld %lld", &money, &interest, &month); getchar();
        printf("Case #%d:\n", i);
        for (j = 1; j <= month; j++)
        {
            money += (money * (double)interest / 12 * 0.008);
            printf("%d %lld\n", j, money);
        }
    }
}

//UTC PROBLEM D
void UTCprobD()
{
    int input, i, j; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++)
    {
        int number, last = 0, result = 0; scanf("%d", &number); getchar();
        for (j = 1; j <= number; j++)
        {
            int temp; scanf("%d", &temp);
            if (temp == last) { temp = 0; result++; }
            last = temp;
        }
        printf("Case #%d: %d\n", i, result);
    }
}

//UAC PROBLEM A
void UACprobA()
{
    struct Applicant { char ID[15], Name[55], Major[35], Position[35]; double GPA; };
    struct Applicant Applicants[5005];
    int input, i, j; scanf("%d", &input); getchar();
    for (i = 0; i < input; i++)
    {
        gets(Applicants[i].ID); gets(Applicants[i].Name); gets(Applicants[i].Major);
        scanf("%lf", &Applicants[i].GPA); getchar(); gets(Applicants[i].Position);
    }
    int cases; scanf("%d", &cases); getchar();
    for (i = 1; i <= cases; i++)
    {
        char findOpen[35], findMajor[35]; double minGPA; int count = 0;
        scanf("%s %s %lf", findOpen, findMajor, &minGPA); getchar();
        for (j = 0; j < input; j++)
        {
            int statusOpen = strcmp(findOpen, Applicants[j].Position);
            int statusMajor = strcmp(findMajor, Applicants[j].Major);
            int statusGPA = Applicants[j].GPA >= minGPA;
            if (!statusOpen && !statusMajor && statusGPA) count++;
        }
        printf("CASE #%d: %d\n", i, count);
    }
}

//UAC PROBLEM B
void resultB(int position, int partition, int *array, int size, long long limit)
{
	long long count = 0;
	int current = -1, i;
	for (i = position; i >= 0; i--)
    {
		if (count + array[i] > limit || i == partition - 2)
        {
			resultB(i, partition - 1, array, size, limit); current = i; break;
		}
		count += array[i];
	}
	if (current >= 0) printf("; ");
	for (i = current + 1; i <= position; i++)
    {
		printf("%d%s", array[i], i == size - 1 ? "" : " ");
	}
}
long long int searchB(int *array, int size, int partition)
{
	long long int left = 1, right = LLONG_MAX, limit = LLONG_MAX;
	while (left < right)
    {
		long long int mid = left + (right - left) / 2, sum = 0;
		int status = -1, index = 0, current = 1;
		while (index < size)
        {
			if (array[index] > mid) status = 0;
			if (sum + array[index] > mid) { current++; sum = 0; }
			if (sum <= mid) { sum += array[index]; index++; }
		}
		if (current <= partition) status = 1;
		if (status == -1) status = 0;
		if (status) { limit = (limit < mid) ? limit : mid; right = mid; }
		else left = mid + 1;
	}
	return limit;
}
void UACprobB()
{
    int input, i, j; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++)
    {
        int cities, staff; scanf("%d %d", &cities, &staff); getchar();
        int values[505];
        for (j = 0; j < cities; j++) scanf("%lld", &values[j]);
        long long int limit = searchB(values, cities, staff);
		resultB(cities - 1, staff, values, cities, limit);
		printf("\n");
    }
}

//UAC PROBLEM C
void sortC(int* array, int low, int high)
{
    if (low < high)
    {
        int middle = low + (high - low) / 2, i, j, k;
        sortC(array, low, middle); sortC(array, middle + 1, high);
        int leftSize = middle - low + 1, rightSize = high - middle;
        int *leftArray = (int*)malloc(leftSize * sizeof(int));
        int *rightArray = (int*)malloc(rightSize * sizeof(int));
        for (i = 0; i < leftSize; i++) leftArray[i] = array[low + i];
        for (j = 0; j < rightSize; j++) rightArray[j] = array[middle + 1 + j];
        i = 0, j = 0, k = low;
        while (i < leftSize && j < rightSize)
        {
            if (leftArray[i] <= rightArray[j]) { array[k] = leftArray[i]; i++; }
            else { array[k] = rightArray[j]; j++; } k++;
        }
        while (i < leftSize) { array[k] = leftArray[i]; i++; k++; }
        while (j < rightSize) { array[k] = rightArray[j]; j++; k++; }
    }
}
void UACprobC()
{
    FILE *db = fopen("testdata.in", "r");
    int input, i, j; fscanf(db, "%d\n", &input);
    for (i = 1; i <= input; i++)
    {
        int number; fscanf(db, "%d\n", &number);
        int *values = (int*)malloc(number * sizeof(int));
        long long int sumA = 0, sumB = 0;
        for (j = 0; j < number; j++) fscanf(db, "%d", &values[j]);
        sortC(values, 0, number - 1);
        for (j = number - 1; j >= 0; j--)
        {
            if (sumA + values[j] - sumB > sumB + values[j] - sumA) sumB += values[j];
            else sumA += values[j];
        }
        printf("Case #%d: %lld\n", i, abs(sumA - sumB));
    }
    fclose(db);
}

//UAC PROBLEM D
void UACprobD()
{
    FILE *db = fopen("testdata.in", "r");
    int input, i, j; fscanf(db, "%d", &input);
    for (i = 1; i <= input; i++)
    {
        int number, target, count = 0, min = INT_MAX, max = INT_MIN;
        fscanf(db, "%d %d", &number, &target);
        int *values = (int*)malloc(number * sizeof(int));
        for (j = 0; j < number; j++)
        {
            fscanf(db, "%d", &values[j]);
            if (min > values[j]) min = values[j];
            if (max < values[j]) max = values[j];
        }
        int *hash = (int*)calloc(max - min + 1, sizeof(int));
        for (j = 0; j < number; j++) hash[values[j] - min]++;
        for (j = 0; j < number; j++)
        {
            int diff = target - values[j];
            if (diff >= min && diff <= max && hash[diff - min] > 0)
            {
                if (diff == values[j] && hash[diff - min] > 1) count++;
                else if (diff != values[j]) count++;
            }
        }
        free(hash);
        printf("Case #%d: %d\n", i, count / 2);
        free(values);
    }
    fclose(db);
}

//EXECUTION
int main() { UTCprobB(); return 0; }