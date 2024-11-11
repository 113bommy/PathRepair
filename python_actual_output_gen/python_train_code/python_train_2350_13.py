t = int(input())

for i in range(t):
    a, b = list(map(int, input().split()))
    ans = 0
    cur = 10
    while b >= cur - 1:
        ans += min(a, b)
        cur *= 10
    print(ans)