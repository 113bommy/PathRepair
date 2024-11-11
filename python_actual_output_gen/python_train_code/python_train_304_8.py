x, y = list(map(int, input().split()))
c = 0
d = 0
for i in range(x):
    a = input()
    for b in range(y):
        if str(b) in a:
            c += 1
    if c == y:
        d += 1
    c = 0
print(d)