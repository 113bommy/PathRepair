n,k,x = list(map(int,input().split(' ')))
a = list(map(int,input().split(' ')))
s = 0
for i in range(len(a)-k):
  s += a[i]
print(s + k*x)
