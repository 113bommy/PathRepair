n, m = map(int, input().split())
s1 = set()
s2 = set()
for _ in range(m):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    if a in s2 or b in s1:
        print(0)
        exit(0)
    s1.add(a)
    s2.add(b)
if not s2:
    s2.add(n)
    s1.add(1)
print(max(0, min(s2) - max(s1)))