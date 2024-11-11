# C. Line

vals = input().split()
A, B, C= int(vals[0]), int(vals[1]), int(vals[2])
max_num = int(5e18)

def gcd_extended(a, b):
  r = a % b
  if r == 0:
    return b, 0, 1
  else:
    g, x, y =  gcd_extended(b, r)
    return g, y, x-(a//b) * y  

if A == 0:
  if C % B == 0:
    print(0, -C//B)
  else:
    print(-1)
elif B==0:
  if C % A == 0:
    print(-C//A, 0)
  else:
    print(-1)
else:
  g, x, y = gcd_extended(A, B)
  if C % g == 0:
    k = C // g
    kx = -k * x
    ky = k * y
    if abs(kx) > max_num or abs(ky) > max_num:
      print(-1)
    else:
      print(kx, ky)
  else:
    print(-1)