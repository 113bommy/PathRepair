t = int(input())

for _ in range(t):
    n, r = map(int, input().split())
    k = min(n-1, r)
    ans = k*(k+1)//2
    if r <= n-1:
        ans += 1
    print(ans)