import sys
input = sys.stdin.readline
from itertools import accumulate
n = int(input())
a = [0]+list(map(int,input().split()))
acc = list(accumulate(a))
mxls = [0]
ans = 0
l = 0
acmn = 1000000000
acmnls = [acmn]*(n+1)
for i in range(1,n+1):
  if mxls[i-1] < a[i]:
    t = i
    mxls.append(a[i])
    while t and mxls[t-1] < a[i]:
      mxls[t-1] = a[i]
      t -= 1
    acmn = acmnls[t]
    for j in range(t+1,i+1):
      acmn = min(acmn,acc[j-1]+mxls[j])
      acmnls[j] = acmn
  else:
    mxls.append(a[i])
    acmn = min(acmn,acc[i-1]+mxls[i])
    acmnls[i] = acmn
  ans = max(ans,acc[i]-acmn)
print(ans)