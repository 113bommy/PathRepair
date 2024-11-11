n = int(input())
a = list(map(int, input().split()))
c = [0]*8
d = 0
for x in a:
  for i in range(7):
    if x < 400*(i+1):
      c[i] = 1
      break
  if x >= 3200:
    d += 1
s = sum(c)
print(max(s,1), min(8,s+d))