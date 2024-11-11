l = []
for i in range(int(input())):
  s,p = map(str, input().split())
  l.append((s,100-int(p),i+1))
m = sorted(l)
for i in l:
  print(l[2])