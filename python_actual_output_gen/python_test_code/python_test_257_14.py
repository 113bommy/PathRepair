n, m, k, L = map(int, input().split())
L += k
ans = 0
if L % m > 0:
    ans = (L - (L % m)) // m
else:
    ans = L // m
if L + k > n or m * ans > n or m > n:
    print(-1)
    exit()
else:
    print(ans)
