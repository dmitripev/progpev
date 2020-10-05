int main()
{
    int x;
    scanf("%d", &x);
    int arr[32];
    int i = 0;
    while (x > 0)
    {
         arr[i] = x % 2;
         x = x / 2;
         ++i;
    }
    printf("%d", arr[i - 5]);
	return 0;
}
