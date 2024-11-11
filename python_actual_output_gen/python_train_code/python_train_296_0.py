n=int(input())
l=list(map(int,input().strip().split()))
pn=[0 for i in range(n)]
c=0
d=1
for i in range(n):
    if l[i]<0:
        c+=1
    if c%2==0:
        pn[i]=1
p=[0 for i in range(n)]
p[0]=pn[0]
for i in range(1,n):
    p[i]=p[i-1]+pn[i]
count=0
if l[i]>0:
    count+=1
for i in range(1,n):
    if pn[i]==1:
        count+=(p[i-1]+1)
    else:
        count+=(i-p[i-1])
a=n*(n+1)//2
b=a-count
print(b,count)