import bisect
s = list(input())
t = list(input())

if len(set(t)-set(s)) > 0:
  print(-1)
  exit()

c = set(s)
dic = {}
for char in c:
  dic[char] = []

for i in range(len(s)):
  dic[s[i]] += [i]

last = -1
r = 0
for char in t:
  tmp = last
  idx = bisect.bisect_right(dic[char], last)
  if idx < len(dic[char]):
    last = dic[char][idx]

  if tmp == last:
    r += 1
    last = dic[char][0]

print(len(s)*r + last + 1)
