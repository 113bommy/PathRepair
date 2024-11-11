n,k=map(int,input().split())
li=list(map(int,input().split()))
d={}
for i in li:
    k=0
    while i!=0:
        try:
            d[i].append(k)
        except KeyError:
            d[i]=[k]
            
        k+=1
        i=i//2
mi=100000000
for i in d.values():
    if len(i)>=k:
        i.sort()
        mi=min(mi,sum(i[:k]))
print(mi)