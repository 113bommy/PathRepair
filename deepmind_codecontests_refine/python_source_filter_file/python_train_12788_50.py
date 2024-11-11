A, B, C, D, E, F = map(int, input().split())

ws = set()
ss = set()
for a in range(0, F+1, A*100):
    for b in range(0, F+1-a, B*100):
        ws.add(a + b)

for c in range(0, F+1, C):
    for d in range(0, F+1-c, D):
        ss.add(c + d)

mx = 0
ans = 0, 0
for w in ws:
    if w == 0:
        continue
    for s in ss:
        x = s * 100 / w
        if w + s <= F and x <= E and mx < x:
            mx = x
            ans = s + w, s

print(*ans)
