n,m,k=map(int,input().split())
s=set()
for i in range(n+1):
  for j in range(m+1):
    s.add(i*(n-j)+(n-i)*j)
if k in s:
  print("Yes")
else:
  print("No")
