s = input()
h = int(s[:2])
m = int(s[3:])
d1 = 30 * (h + m/60)
d2 = 6 * m
if d1 > 360:
  d1 -= 360
if d2 > 360:
  d2 -= 360
print(str(d1) + " " + str(d2))