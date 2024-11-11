from copy import deepcopy
n,x = map(int,input().split())
a = list(map(int,input().split()))
a *= 2
als = deepcopy(a[:n])
ans = [sum(als)]
for k in range(1,n):
  for i in range(n):
    als[i] = min(als[i],a[n+i-k])
  ans.append(sum(als)+x*k)
print(min(ans))