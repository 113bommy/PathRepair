n, k = map(int, input().split())
v = [int(e) for e in input().split()]
m = min(n, k)
result = 0
for i in range(m + 1):
  for j in range(i + 1):
    t = v[:j]
    t.extend(v[n - (i - j):])
    t.sort()
    k = m - i
    while len(t) > 0 and k > 0 and t[0] < 0:
      t = t[1:]
      k -= 1
    l = sum(t)
    if l > result:
      result = l
print(result)
