import math
n,x=map(int,input().split())
a=list(map(int,input().split()))
x-=1
c=(x+1)%n
min1=math.inf
min2=-1
min3=-1
for i in range(n):
    if(min1>=a[c]):
        min1=a[c]
        min2=c
        min3=n-i-1
    c=(c+1)%n


flag=False
c=min2

#print(min1,min2,min3)
for i in range(n):
    a[i]-=min1


for i in range(n):
    a[c]-=1
    
    if(x==c):
        break
    c=(c+1)%n
a[min2]=min3+min1*n
print(*a)
