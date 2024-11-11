n,q = map(int,input().split())
s = "0"+input()+"0"
info = [input().split() for i in range(q)]

def solve(pos):
  for i in range(q):
    if s[pos] == info[i][0]:
      if info[i][1] == "L":
        pos = pos - 1
      else:
        pos = pos + 1
    if pos == 0:
      return True
    elif pos == n+1:
      return False
  return False

def solve2(pos):
  for i in range(q):
    if s[pos] == info[i][0]:
      if info[i][1] == "R":
        pos = pos - 1
      else:
        pos = pos + 1
    if pos == 0:
      return True
    elif pos == n+1:
      return False
  return False
ans = n
ng = n+2
ok = 0
while abs(ng - ok) > 1:
  mid = (ng+ok)//2
  if solve(mid):
    ok = mid
  else:
    ng = mid

ans = ans - ok

s = s[::-1]

ng = n+2
ok = 0
while abs(ng - ok) > 1:
  mid = (ng+ok)//2
  if solve2(mid):
    ok = mid
  else:
    ng = mid

ans = ans - ok

print(ans)