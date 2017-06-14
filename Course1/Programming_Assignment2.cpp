#include <bits/stdc++.h>

long long Count_inv(int arr[], int size)
{
	int *t = (int *)malloc(sizeof(int)*size);
	return sort(arr, t, 0, size - 1);
}

long long sort(int arr[], int t[], int l, int r)
{
int m;
long long result = 0;
if (r > l)
{
	m = (r + l)/2;

	result += sort(arr, t, l, m);
	result += sort(arr, t, m+1, r);
	result += merge(arr, t, l, m+1, r);
}
return result;
}

long long merge(int arr[], int t[], int l, int m, int r)
{
int i, j, k;
long long result = 0;

i = l; 
j = m; 
k = l;
while ((i <= m - 1) && (j <= r))
{
	if (arr[i] <= arr[j])
	{
	t[k++] = arr[i++];
	}
	else
	{
	t[k++] = arr[j++];
	result = result + (m - i);
	}
}

while (i <= m - 1)
	t[k++] = arr[i++];

while (j <= r)
	t[k++] = arr[j++];

for (i=l; i <= r; i++)
	arr[i] = t[i];

return result;
}

int main()
{
    FILE *fp = NULL;
    int value;
    int i = -1;
    int integers[100000];
    if ((fp = fopen ("IntegerArray.txt", "r")) == NULL)
        return -1;

    while (fscanf (fp, "%i", &value) && !feof(fp) && ++i < 100000 ) 
        integers[i] = value;

    fclose (fp);
    printf("%lld \n", Count_inv(integers, 100000));
    return 0;
}
