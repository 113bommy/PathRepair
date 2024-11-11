import fractions
n = int(input())
a = list(map(int,input().split()))
m = []
l = [0]
r = [0]
for i in range(n):
  l.append(fractions.gcd(l[i],a[i]))
  r.append(fractions.gcd(r[i],a[-i-1]))
r.reverse()
for i in range(n):
  m.append(fractions.gcd(l[i],r[i+1]))
print(max(m))