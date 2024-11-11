n=int(input())
a=list(map(int,input().split()))
b=[0]*n
for i,j in enumerate(a,1):
  b[j-1]=i
print(*b)
