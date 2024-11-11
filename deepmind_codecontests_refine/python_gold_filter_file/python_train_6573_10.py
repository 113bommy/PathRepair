a,k = list(map(int,input().split()))
c = list(map(lambda x: int(x)%k,input().split()))
d = {}
n = 0
for i in list(set(c)):
    d[i]=0
for i in c:
    d[i]+=1
    n = 0
for i in d.keys():
    if (k-i)%k in d:
        if i == (k-i)%k :
            n+=d[i]-d[i]%2
            continue
        n+=min(d[i],d[(k-i)%k])
print(n)