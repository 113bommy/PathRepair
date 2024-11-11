n, q = input(), sorted(map(int, input().split()))
t = 0
h = 0
for m in q:
    if m > t:
        t += m
        h += 1
print(h)
