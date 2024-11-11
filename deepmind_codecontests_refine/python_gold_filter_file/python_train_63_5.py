n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
d=[]
for x in range(len(a)):
    if k%a[x]==0:
        d.append(a[x])
print(k//max(d))
