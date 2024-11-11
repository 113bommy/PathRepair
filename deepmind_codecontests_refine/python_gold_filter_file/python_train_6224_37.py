s = input()
n = 0
ans = 0
mods = [0]*2019
mods[0] = 1
for i, j in enumerate(reversed(s)):
  n += int(j)*pow(10, i, 2019)
  n %= 2019
  mods[n] += 1
for i in mods:
  ans += i*(i-1)//2
print(ans)