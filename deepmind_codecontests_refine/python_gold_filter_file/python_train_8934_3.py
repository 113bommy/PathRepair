n,l = map(int,input().split())
ls = [input() for i in range(n)]
sm = sum([len(s) for s in ls])
ls.sort()
num = [0]*(sm+1)
for i in range(n):
  if i == 0:
    for j in range(len(ls[i])):
      num[j+1] = 1
  else:
    x = ls[i]
    p = ls[i-1]
    cnt = 0
    while cnt < min(len(x),len(p)):
      if x[cnt] == p[cnt]:
        cnt += 1
      else:
        break
    num[cnt+1] -= 1
    for j in range(cnt+2,len(x)+1):
      num[j] += 1
ans = 0
def d2(x):
  if x == 0:
    return 0
  cnt = 0
  while x%2 == 0:
    cnt += 1
    x //= 2
  return 2**cnt
for i in range(sm+1):
  ans ^= d2(l+1-i)*(num[i]%2)
if ans:
  print("Alice")
else:
  print("Bob")