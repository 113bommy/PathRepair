import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    s = sum(b)
    x = n * (n + 1) // 2
    ans = "YES"
    if s % x:
        ans = "NO"
    s //= x
    a = []
    for i in range(n):
        if (b[(i - 1) % n] - b[i] + s) % n:
            ans = "NO"
            break
        a.append((b[(i - 1) % n] - b[i] + s) // n)
        if not a[-1]:
            ans = "NO"
            break
    print(ans)
    if ans == "NO":
        continue
    print(*a)