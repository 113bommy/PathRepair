n, c = map(int, input().split())
tab = list(map(int, input().split()))
if n == 1:
    print(1)
else:
    ans = 0
    for i in range(1, n):
        ans += 1
        if tab[i] - tab[i - 1] > c:
            ans = 1
    print(ans)