N = int(input())
a = list(map(int, input().split()))
s = set()
r = 0
for i in a:
  if i < 3200:
    s.add(i//400)
  else:
    r += 1
print(max(len(s), 1), min(len(s)+r, 8))