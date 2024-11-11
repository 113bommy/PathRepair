h,w = map(int,input().split())
s = list(map(int,input().split()))
g = list(map(int,input().split()))
s[0] -= 1
s[1] -= 1
g[0] -= 1
g[1] -= 1
raw = []
seen = []
for _ in range(h):
  tmp = input()
  raw.append(tmp)
  t = []
  for j in range(w):
    if tmp[j] == '.':
      t.append(0)
    else:
      t.append(1)
  seen.append(t)
#print(seen)
now = [s]
ans = 0
def check(ii,jj):
  if 0 <= ii < h and 0 <= jj < w:
    if seen[ii][jj] == 0:
      seen[ii][jj] = 1
      now.append([ii,jj])
while now:
  for x in now:
    a,b = x
    check(a-1,b)
    check(a+1,b)
    check(a,b-1)
    check(a,b+1)
  if seen[g[0]][g[1]] == 1:
    print(ans)
    break
  ans += 1
  last = now
  now = []
  for x in last:
    a,b = x
    for di in range(-2,3):
      for dj in range(-2,3):
        check(a+di,a+dj)
else:
  print(-1)