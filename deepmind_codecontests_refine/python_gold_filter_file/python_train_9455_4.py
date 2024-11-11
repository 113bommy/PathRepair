n = int(input())
a = list(map(int,input().split()))
a.sort()
p = a[-1]
q = a[0]
m = p
for x in a:
  if abs(p-2*x)<m:
    q = x
    m = abs(p-2*x)
print(p,q) 