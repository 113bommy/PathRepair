n,x=map(int,input().split())
a=list(map(int,input().split()))
x-=1
y=max(0,min(a))
for i in range(n):
    a[i]-=y
flag=False
cnt=0
for i in range(x,-1,-1):
    if a[i]==0:
        a[i]=cnt+y
        flag=True
        break
    a[i]-=1
    cnt+=1
for i in range(n-1,x,-1):
    if flag:
        break
    if a[i]==0:
        a[i]=cnt+y
        break
    a[i]-=1
    cnt+=1
print(*a)    