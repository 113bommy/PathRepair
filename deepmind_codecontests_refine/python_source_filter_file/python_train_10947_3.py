t = int(input())
for _ in range(t):
    ans = 0
    n = int(input())
    while n % 5 == 0:
        ans += 3
        n /= 5
    while n % 3 == 0:
        ans += 2
        n /= 3
    while n % 2 == 0:
        ans += 1
        n /= 2
    if n == 1:
        print(ans)
    else:
        print(-1)