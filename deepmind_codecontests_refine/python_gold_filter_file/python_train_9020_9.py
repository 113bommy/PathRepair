def position_zip(a, flag):
  j = 0
  d = {}
  for i in sorted(a):
    if i in d:
      continue
    d[i] = j
    j += 1
  if flag == 1:
    return d
  return [d[i] for i in a]

n=int(input())
a=list(map(int,input().split()))
b=[]
for i in a:
  b.append(i-1)
  b.append(i)
  b.append(i+1)
d=position_zip(b,1)
l=len(d)
ans=[[]for _ in range(l)]
dp=list(range(l))
ma=0
ansi=0
for i in range(n):
  x=dp[d[a[i]-1]]
  y=dp[d[a[i]]]
  if len(ans[x])!=0 and x!=y:
    y=dp[d[a[i]]]=x
    ans[y].append(i+1)
  elif len(ans[y])==0:
    ans[y].append(i+1)
  if len(ans[y])>ma:
    ma=len(ans[y])
    ansi=y
print(ma)
print(*ans[ansi])
