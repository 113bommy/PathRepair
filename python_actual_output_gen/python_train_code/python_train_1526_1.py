from itertools import groupby
t = int(input())
for _ in range(0,t):
    n = int(input())
    a = [int(i) for i in input().split()]
    sg = [list(g) for s,g in groupby(a)]
    ans = 0
    if len(sg) == 1 or len(sg) == 2:
        ans = 0
    elif sg[0][0] == 1:
        for i in range(1,len(sg),2):
            ans += len(sg[i])
    else:
        for i in range(2,len(sg),2):
            ans += len(sg[i])
    print(ans)