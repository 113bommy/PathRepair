s = input()
t = input()
n = len(s)
m = len(t)
a,x = m,m
for i in range(n-m+1):
  x=m
  for j in range(m):
    x -= s[i+j] == t[j]
  a = min(a,x)
print(a)