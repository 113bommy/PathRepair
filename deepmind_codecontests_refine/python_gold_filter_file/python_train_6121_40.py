n=int(input())
a=list(map(int,input().split()))
b=[-1]*n
for i,j in enumerate(a):
  b[j-1]=i+1
print(*b)