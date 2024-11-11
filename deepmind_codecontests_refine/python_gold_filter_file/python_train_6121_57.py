n=int(input())
a=list(map(int,input().split()))
b=[0]*n
for i,q in enumerate(a):
  b[q-1]=i+1
print(*b)