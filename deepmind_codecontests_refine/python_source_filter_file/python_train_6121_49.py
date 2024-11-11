n=int(input())
a=list(map(int,input().split()))
b=a
k=1
for i,j in enumerate(a,1):
  b[j-1]=i
print(*b)
