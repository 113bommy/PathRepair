import sys
n,m=map(int,sys.stdin.readline().split())
a=list(map(int,input().split()))
a.sort()
suma=0
for i in range(m):
  if a[i]<=0:
    suma+=(-a[i])
  else:
    suma-=a[i]
print(suma)