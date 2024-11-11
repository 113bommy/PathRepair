def gcd(a,b):
  if a== 0:
    return b
  return gcd(b%a,a)

a,b,c,d = map(int,input().strip().split())
nr , dr = 0, 0
if a/b == c/d:
  print(0)
elif a/b > c/d:
  nr = a*d - b*c
  dr = a*d
  commDiv = gcd(nr,dr)
  print(str(nr//commDiv) + "/" + str(dr//commDiv))
else:
  nr = b*c - a*d
  dr = b*c
  commDiv = gcd(nr,dr)
  print(str(nr//commDiv) + "/" + str(dr//commDiv))

