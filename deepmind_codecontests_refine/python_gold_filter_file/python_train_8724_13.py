n,m = map(int,input().split())
S = set(range(1,m+1))
for i in range(n):
  a,*b = map(int,input().split())
  S &= set(b)
print(len(S))
  