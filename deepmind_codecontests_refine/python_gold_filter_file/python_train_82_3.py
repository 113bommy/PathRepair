t = int(input())

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

for i in range(t):
  a, b, c, d = list(map(int, input().split()))
  if a<b or b>d or a%b>c:
    print("No")
  elif b==d:
    print("Yes")
  elif b-gcd(b, d)<=c:
    print("Yes")
  else:
    print("No")