n=int(input())
a=list(map(int,input().split()))
b=a
for i,j in enumerate(a):
  b[j-1]=i+1
print(*b)
