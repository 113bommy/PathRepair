import math
n=int(input())
a=list(map(int,input().split()))
p=[0]*n 
p[0]=a[0]
for i in range(1,n):
    p[i]=p[i-1]+a[i]
q=int(input())
for i in range(q):
    l,r=tuple(map(int,input().split()))
    print(math.floor((p[r-1]-p[l-1])/10))