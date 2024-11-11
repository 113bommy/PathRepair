import sys

n=int(input())
a=list(map(int,input().split()))
x=[0]*(n+1)
  
for i in range(n):
 x[a[i]]=i+1
x.remove(0)

print(*x,sep=", ")
