k,q = map(int,input().split())
d = list(map(int,input().split()))
al = []
for i in range(q):
    n,x,m = map(int,input().split())
    pd = []
    count = 0
    for j in range(k):
        pd.append(d[j]%m)
        if d[j]%m == 0:
            count += 1
    a = sum(pd)
    ans = x
    ans += a*((n-1)//k)
    #print(pd)
    c = 0
    for j in range((n-1)%k):
        ans += pd[j]
        if pd[j] == 0:
            c += 1
    al.append(n-1-(ans//m)-count*((n-1)//k)-c)
for i in range(q):
    print(al[i])