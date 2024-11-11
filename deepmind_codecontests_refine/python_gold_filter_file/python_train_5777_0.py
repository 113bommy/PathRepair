n=int(input())
a=list(range(1,n+1))
if n==1:print(1);print(1);exit(0)
if n==2 or n==3:print(n-1);del a[-2];print(*a);exit(0)
if n==4:print(4);print(3,1,4,2);exit(0)
if n==5:print(5);print(5,3,1,4,2);exit(0)
print(n)
for i in range(0,n-3,2):
    a[i],a[i+3]=a[i+3],a[i]
print(*a)