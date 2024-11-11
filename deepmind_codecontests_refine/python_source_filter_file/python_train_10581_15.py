n,m = map(int,input().split())
q = 10^9
for s in range(0,n):
    e = list(map(int,input().split()))
    if (e[0] / e[1]) * m<=q:
        q = (e[0] / e[1]) * m
print(q)        