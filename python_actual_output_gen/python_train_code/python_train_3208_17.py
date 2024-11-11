n, x0, y0 = map(float, input().split())

t = set()
for _ in range(int(n)):
    x,y = map(float, input().split())
    if x == x0:
        t.add(0)
    else:
        t.add((y-y0)/(x-x0))
print(len(t))