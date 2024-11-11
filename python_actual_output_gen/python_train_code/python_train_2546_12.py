d, g = map(int, input().split())
p = [0]*d
c = [0]*d
for i in range(d):
  p[i], c[i] = map(int, input().split())
 
ans = 10**6
 
for i in range(2**d):
  cnt = 0
  sum = 0
  k = -1
  for j in range(d):
    if (i >> j) & 1:
      sum += (j+1)*100*p[j]+c[j]
      cnt += p[j]
    else:
      k = j
  if sum < g:
    s1 = 100 * (k + 1)
    need = (g - sum + s1 - 1) // s1
    if need >= p[k]:
      continue
    cnt += need
    ans = min(ans, cnt)
print(ans)