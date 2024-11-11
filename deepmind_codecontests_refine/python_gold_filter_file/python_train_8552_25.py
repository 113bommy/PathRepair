n=int(input())
a=input().split()
for i in range(2*n):
    a[i]=int(a[i])
flag=True    
for i in range(2*n):
    if(a[i]!=a[0]):
        flag=False
if(flag):
    print(-1)
else:
    a.sort()
    print(*a)