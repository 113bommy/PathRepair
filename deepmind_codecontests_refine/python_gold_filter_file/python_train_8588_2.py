s = d = 0
t = [list(map(int, input().split())) for i in range(int(input()))]
for l, r in sorted(t, key=lambda q: q[1]):
    if l > d: s, d = s + 1, r
print(s)