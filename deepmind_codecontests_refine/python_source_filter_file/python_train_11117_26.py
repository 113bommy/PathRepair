n, m = map(int, input().split())
ac = [0]*n
wa = [0]*n
a = 0
w = 0
for i in range(m):
  p, s = input().split()
  p = int(p)-1
  if ac[p] == 0, s == "AC":
    ac[p] += 1
    a += 1
    w += wa[p] 
  elif ac[p] == 0, s == "WA":
    wa[p] += 1
print(a,w)