n, k, a, b = map(int, input().split())
ca = "G" 
cb = "B" 
if a < b:
  a, b = b, a
  ca, cb = cb, ca

if k > 1 and a > b:  
  v1 = (a-b-1) // (k-1)  
  v2 = (a-b-1) % (k-1)
  if not v2:
    v2 = k - 1
    v1 -= 1
  v3 = b - v1
  if v3 < 0:
    print("NO")
  else:
    print((ca*k + cb) * v1 + (ca + cb) * v3 + ca * (v2 + 1))  
else: 
  if a - b > 1:
    print("NO")
  else:
    print((ca + cb) * b + ca * (a-b))  
