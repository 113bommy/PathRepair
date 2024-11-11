import bisect
n,q = map(int,input().split())
l = [list(map(int,input().split())) for i in range(n)]
l = sorted(l,key = lambda x: x[2])
d = [int(input()) for i in range(q)]

ans = [-1]*q
skip = [-1]*q
for s,t,x in l:
    le = bisect.bisect_left(d,s-x)
    ri = bisect.bisect_left(d,t-x)
    while le < ri:
        if skip[le] == -1:
            ans[le] = x
            skip[le] = ri
            le += 1
        else:
            le = skip[le]

for i in ans:
    print(i)
