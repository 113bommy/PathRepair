n,m=map(int,input().split())

s=set(range(1,m+1))
for i in range(n):
  k,*A=map(int,input().split())
  s&=set(A)
print(len(s))