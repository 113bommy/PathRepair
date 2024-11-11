def solve():
    n, a, b = map(int, input().split())
    if a == 1:
        if (n - 1) % b == 0:
            return 'YES'
        return 'NO'
    poww = 1
    while poww <= n:
        if poww % b == n % b:
            return 'YES'
        poww *= a
    return 'NO'
t = int(input())
for _ in range(t):
    ans = solve()
    print(ans)