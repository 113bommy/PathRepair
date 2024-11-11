import bisect
s = input()
t = input()
d = {}
for i in range(len(s)):
  if s[i] in d:
    d[s[i]] += [i]
  else:
    d[s[i]] = [i]
c = 0
cur = 0
for i in t:
  if i not in d:
    print(-1)
    exit()
  if cur < d[i][-1]:
    cur = d[i][bisect.bisect_left(d[i],cur)]
    continue
  else:
    cur = d[i][0]
    c += 1
print(c*len(s)+cur+1)