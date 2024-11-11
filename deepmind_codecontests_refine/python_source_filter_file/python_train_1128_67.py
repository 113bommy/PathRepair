n=int(input())
a=list(map(int,input().split()))
c=[0]*8
sums=0
sai=0
for i in a:
    if i<3200:
        c[i//400]=1
    else:
        sai+=1
sums=sum(c)
print(sums,sums+sai)