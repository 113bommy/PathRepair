N,K = map(int, input().split())
PList = list(map(int, input().split()))
CList = list(map(int, input().split()))

ans = -1*(10**18)
for si in range(N):
  x = si
  s = list()
  total = 0
  l = 0
  while(1):
    x = PList[x]-1
    s.append(CList[x])
    l += 1
    total += CList[x]
    if x == si:
      break
  t = 0
  for i in range(l):
    t += s[i]
    if i+1 > K:
      break
    now = t
    if total > 0:
      e = (K-i-1)//l
      now += total*e
    ans = max(ans, now)  
print(ans)
    