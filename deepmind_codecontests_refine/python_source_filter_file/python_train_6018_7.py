#10:30
s = input()
n = len(s)
now = [1,0,0,0,0,0,0,0,0,0,0,0,0]
for i in range(n):
  last = now
  now = [0 for _ in range(13)]
  here = s[i]
  if here == '?':
    for k in range(10):
      for j in range(13):
        now[(10*j+k)%13] += last[j]
  else:
    k = int(here)
    for j in range(13):
      now[(10*j+k)%13] += last[j]
  for j in range(13):
    now[j] %= 10**9+7
print(now[5])