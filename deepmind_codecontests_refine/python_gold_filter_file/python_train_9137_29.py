n,p = map(int, input().split())
s = list(map(int, list(input())))
if p in (2, 5):
  print(sum(i+1 for i in range(n) if s[i]%p == 0))
  exit(0) 
ans = g = 0
d = [0]*p
d[0] = 1
t = 1
for i in range(n-1,-1,-1):
    g = (g + s[i]*t)%p
    ans += d[g]
    d[g] += 1
    t = (t*10)%p
print(ans)