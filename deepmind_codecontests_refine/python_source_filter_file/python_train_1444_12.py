n = int(input())
s = int(input())

flag = False
if s > n or (n//2)<s<n:
  print(-1)
  exit()
  
if s == n:
  print(n+1)
  exit()

def chk(b, n):
  if n//b == 0:
    return n
  else:
    return chk(b,n//b) + n%b

for b in range(2, int(n**0.5)+1):
  if chk(b, n) == s:
    print(b)
    flag = True
    exit()

for i in range(int(n**0.5), 0, -1):
  b = (n-s)//i + 1
  if chk(b, n) == s:
    if b > 1:
      print(b)
      flag = True
      exit()

if flag == False:
  print(-1)