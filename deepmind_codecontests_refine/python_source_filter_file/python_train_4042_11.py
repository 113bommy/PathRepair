import sys
input = sys.stdin.readline
n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
b = []
c = []
for i in range(n):
  if i%2:
    b.append(a[i//2])
    c.append(a[i//2+(n+1)//2])
  else:
    b.append(a[i//2+n//2])
    c.append(a[i//2])
if n>=3 and n%2:
  b[-1],b[-3] = b[-3],b[-1]
  c[0],c[2] = c[2],c[0]
ansb = 0
ansc = 0
for i in range(n-1):
  ansb += abs(b[i+1]-b[i])
  ansc += abs(c[i+1]-c[i])
print(max(ansb,ansc))