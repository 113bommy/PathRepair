s = input().split()
n, m = int(s[0]), int(s[1])
cl = list(map(int, input().split()))
com = list(map(int, input().split()))
res = False
for i in range(n):
  for j in range(i+1, n):
    e = True
    t = cl[i:j+1]
    for k in range(1, m+1):
      e = t.count(k)==com[k-1] and e
    if e:
      res = True
      break
    
if res: print('YES')
else: print('NO')