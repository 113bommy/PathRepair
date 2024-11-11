n,m=map(int, input().split())
A=set(range(1, m+1))
for _ in range(n):
  a,*b=map(int, input().split())
  A = A & set(b)
print(len(A))