ns = input()
n = int(ns[:-1])
s = ns[len(ns) - 1]

# 1/3, 2/4, +3 5/7, 6/8, +3, 9/11, 10/12, +3 13/15, 14/16
r = n - 1
if n % 4 == 0 or (n + 1) % 4 == 0:
  d = int(n / 2) - 1
  r = n - 3
else:
  d = n // 2
t = d * 6 + r
if s == "f":
  t += 1
elif s == "e":
  t += 2
elif s == "d":
  t += 3
elif s == "a":
  t += 4
elif s == "b":
  t += 5
elif s == "c":
  t += 6

print(t)
