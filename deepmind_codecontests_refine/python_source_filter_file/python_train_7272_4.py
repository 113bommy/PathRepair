n = int(input())
t = list(map(int, input().split()))
a = list(map(int, input().split()))
MOD = 10**9 + 7
t_max = max(t)
for i in range(n):
  if a[i] == t_max:
    max_ind = i
    break
if t[max_ind] != a[max_ind] or t[-1] != a[0]:
  print(0)
else:
  idx = []
  before = 0
  for i in range(n):
    if before == t[i]:
      idx .append(i)
    before = t[i]
  if len(idx) == 0:
    print(1)
  else:
    new_idx = []
    for j in idx:
      if j < n-1 and a[j] == a[j+1]:
        new_idx.append(j)
    if len(new_idx) == 0:
      print(0)
    else:
      ans = 1
      for k in new_idx:
        ans *= min(t[k], a[k])
        ans %= MOD
      print(ans)