pre = []
prev = ['']
for i in range(1, 3):
    cur = [s + '4' for s in prev] + [s + '7' for s in prev]
    pre.extend(cur)
    prev = cur

l = sorted(map(int, pre))

x, y = map(int, input().split())
res = 0

for e in l:
    if e < x: continue
    res += e * (min(e, y) - x + 1)
    x = e + 1
    if x > y: break

print(res)