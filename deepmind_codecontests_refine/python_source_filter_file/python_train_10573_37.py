n = list(map(int, input().split()))[:]
a = 0

k2 = n[0]
k3 = n[1]
k5 = n[2]
k6 = n[3]

if k2 - k5 <= 0:
  a = k2
  if k2 - k6 < 0:
    a = k6
else:
  a = k5
  if k6 - k5 <= 0:
    a = k6
  
x1 = 256 * a

k2 -= a

b = k2

if k3 - k2 <= 0:
  b = k3

x2 = 32 * b

total = x1 + x2

print(total)