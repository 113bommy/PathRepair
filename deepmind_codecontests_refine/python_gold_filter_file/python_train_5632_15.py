n, k = map(int, input().split())
f = {}
for t in map(int, input().split()):
    if t in f:
        f[t] += 1
    else:
        f[t] = 1
f = list(f.values())
a = max(f)
while a > 0:
    if sum([x//a for x in f]) >= n:
        print(a)
        exit()
    else:
        a -= 1
print(a)