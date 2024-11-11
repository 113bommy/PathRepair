n,m=map(int,input().split())
S=set(range(1,m+1))
for i in range(n):
  k,*A=map(int,input().split())
  S&=set(A)
print(len(S))
  