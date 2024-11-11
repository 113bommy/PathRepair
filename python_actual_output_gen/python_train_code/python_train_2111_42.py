n=int(input())
a=map(int,input().split())
d=[0]*n
for i in range(0,n):
  d[a[i]-1]=i
print(*d)  