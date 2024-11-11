n = int(input())
a = list(map(int,input().split()))
a.sort()
ls = [1]*(10**6+1)
ans = 0
for idx,i in enumerate(a):
  if ls[i] == 0:
    continue
  if idx < n-1 and a[idx+1] != i:
    ans += 1
  for j in range(i,10**6+1,i):
    ls[j] = 0
print(ans)