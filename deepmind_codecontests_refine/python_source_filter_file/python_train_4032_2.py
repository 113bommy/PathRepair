n = int(input())
d = [0]*100010
l = []
le = []
for _ in range(n-1):
    u,v = map(int,input().split())
    d[u]+=1
    d[v]+=1
    l.append(u)
    l.append(v)
r = 0
for i in range(1,max(l)+1):
    if(d[i]==1):
        le.append(i)
    if(d[i]>2):
        if(not r):
            r = i
        else:
            print('NO')
            exit(0)
print('YES')
if(not r):
    print(1)
    print(min(le),max(le))
else:
    x = len(le)
    print(x)
    le.sort()
    for i in range(1,x+1):
        print(r,le[i-1])