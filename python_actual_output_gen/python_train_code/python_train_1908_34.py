n,m,k = map(int,input().split())
a = set()
for i in range(n+1):
  for j in range(m+1):
    a.add(m*i+n*j-i*j)
print('YNeos'[k not in a::2])