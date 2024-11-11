n,m,v,p = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
b = [0]*(n+1)
for i in range(n):
  b[i+1] = b[i] + a[i]

def judge(x):
  if x >= n-p: return True
  if a[x] + m < a[n-p]: return False
  safe = m*(n-2) + a[x]*(n-p-x-1) - b[n-p] + b[x+1]
  return safe >= m*(v-1)
ok = n-p
ng = -1
while ok-ng > 1:
  mid = (ok+ng)//2
  if judge(mid):
    ok = mid
  else:
    ng = mid
print(n-ok)