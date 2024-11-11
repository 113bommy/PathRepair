a = int(input())
n = list(map(int,input().split()))
t = sum(n)
if t%2 != 0: print(*n)
else:
    t = t//2
    n.sort()
    p = sum(n[:a])
    if t == p:
        print(-1)
    else: print(*n)