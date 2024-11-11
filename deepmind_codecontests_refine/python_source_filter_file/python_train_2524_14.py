import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = [int(_) for _ in input().split()]
    s = 0
    cnt = 0
    for i in range(n):
        s += a[i]
        if a[i] % x != 0:
            cnt += 1
    if cnt == 0:
        print(-1)
        continue
    if s % x != 0:
        print(n)
    else:
        l, r = 0, 0
        for i in range(n):
            if a[i] % x != 0:
                l = i
                break
        for i in range(n-1, -1, -1):
            if a[i] % x != 0:
                r = i
                break
        ans = n - l - 1
        ans = max(ans, r + 1)
        print(ans)
