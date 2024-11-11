n=int(input())
a=list(map(int,input().split()))
d=[0]*n
for i in range(0,n):
  d[a[i]]=i

print(*d)  