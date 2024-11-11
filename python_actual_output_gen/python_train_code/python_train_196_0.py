n, m, k = map(int,input().split())
l = [0] + list(map(int,input().split()))
k = [0] + list(map(int,input().split()))
d = list(map(int,input().split()))
s = 0
if len(l) == len(set(l)) and len(d) == len(set(d)):
  for i in d:
    c = i
    c = l.index(c)
    c = k[c]
    h = []
    for x in range(len(k)):
        if k[x] == c:
            h.append(l[x])
    if l[i] != max(h):
        s += 1
  print(s)
