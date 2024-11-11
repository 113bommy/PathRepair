q = int(input())
for i in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    t = a[-1]
    ans = 0
    for j in range(2, n + 1):
        if t > a[-j]:
            t = a[-j]
        else:
            ans += 1
    print(ans)
