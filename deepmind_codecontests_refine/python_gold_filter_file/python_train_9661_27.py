n = int(input())
ps = []
mis = []
for _ in input().split():
  item = int(_)
  if item >= 0:
    ps.append(item)
  else:
    mis.append(item)
  
mis.sort(reverse = True)
ps.sort()
if len(mis) == 0:
  mis = [ps[0]]
  ps = ps[1:]
if len(ps) == 0:
  ps = [mis[0]]
  mis = mis[1:]
print(sum(ps) - sum(mis))

pre = mis[0]
for p in ps[:len(ps) - 1]:
  print(pre, p)
  pre -= p
print(ps[-1], pre)
pre = ps[-1] - pre
for m in mis[1:]:
  print(pre, m)
  pre -= m


