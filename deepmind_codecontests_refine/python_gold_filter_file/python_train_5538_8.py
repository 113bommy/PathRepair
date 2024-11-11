q = int(input())
for i in range(q):
    h, n = map(int, input().split())
    p = list(map(int, input().split()))
    p.append(0)
    ans = 0
    a = 0
    j = 2
    while j <= n:
        if p[j - 1] - p[j] > 1:
            ans += 1
            j += 1
        else:
            j += 2
    print(ans)