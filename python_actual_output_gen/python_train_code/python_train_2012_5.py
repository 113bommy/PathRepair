a, b = map(int, input().split())
e = []
for i in range(a):
    c, d = map(int, input().split())
    if b>=d:
        e.append(c)
print(min(e) if not e == [] else "ELT")