#00:46
n,k = map(int,input().split())
raw = [[] for _ in range(n)]
for _ in range(n):
  t,d = map(int,input().split())
  t -= 1
  raw[t].append(d)
only = []
other = []
for i in range(n):
  if len(raw[i]) != 0:
    raw[i].sort(reverse = True)
    only.append(raw[i][0])
    other += raw[i][1:]
only.sort(reverse = True)
only += [0 for _ in range(k)]
other.sort(reverse = True)
now = sum(only[:k])
can = [now + k * k]
for j in range(k):
  try:
    now -= only[k-1-j]
    now += other[j]
    can.append(now + (k-1-j) ** 2)
  except:
    break
print(max(can))