T = int(input())
for t in range(T):
    n = int(input())
    p = list(map(int, input().split()))
    ans = 1
    if p.count(p[0]) == n:
        ans = 2
    print(ans)
            