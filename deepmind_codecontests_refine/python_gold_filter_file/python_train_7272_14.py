n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
ai = [-1] * n
bi = [-1] * n
r = [-1] * n
ai[0]=a[0]
bi[-1]=b[-1]
for i in range(1,n):
  if a[i] > a[i-1]:
    ai[i] = a[i]
for i in range(n-2,-1,-1):
  if b[i] > b[i+1]:
    bi[i] = b[i]
ret = 1
r = [0] * n
for i in range(n):
  if ai[i]!=bi[i] and ai[i]!=-1 and bi[i]!=-1:
    print(0)
    exit()
  elif ai[i]==-1 and bi[i]==-1:
    ret *= min(a[i], b[i])
    ret %= 10**9+7
  else:
    r[i]=max(ai[i], bi[i])
x = 0
for i in range(n):
  x = max(x, r[i])
  if x!=a[i]:
    print(0)
    exit()
x = 0
for i in range(n-1, -1, -1):
  x = max(x, r[i])
  if x!=b[i]:
    print(0)
    exit()
print(ret)