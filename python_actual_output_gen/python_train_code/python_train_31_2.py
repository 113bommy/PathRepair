T = int(input())

def gcd(a, b):
  if a < b:
    a, b = b, a
  if b == 0:
    return 0
  while a % b:
    a, b = b, a % b
  return b

while T:
  T -= 1
  
  A, B, C, D = map(int, input().split())
  
  if B > A or B > D:
    print("No")
  else:
    p = A - (A - C + B - 1) // B * B
    r = D % B
    g = gcd(r, B - r)
    if p < 0:
      print("No")
    elif r == 0 or (C - p) // g * g + p - B + r >= 0:
      print("Yes")
    else:
      print("No")