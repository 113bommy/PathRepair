t = int(input())
for i in range(0, t):
    n = int(input())
    ans = 0;
    for j in range(0, n):
        ans += (n - 2*j)*(n - 2*j)*(n/2-j)
    print(ans)