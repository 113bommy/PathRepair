n = int(input())
for i in range(n):
    t = list(input().split())
    t = [int(j) for j in t]
    t = sorted(t)
    if t[0] <= t[1]//2:
        res = t[1]%(t[1]//2 + 1)
    else:
        res = t[1]%t[0]
    print(res)