t = int(input())
for case in range(t):
    n, k  = [int(x) for x in input().split(' ')]
    a = [int(x) for x in input().split(' ')]
    a.sort()
    ans = a[-1] + sum(a[:k])
    print(ans)