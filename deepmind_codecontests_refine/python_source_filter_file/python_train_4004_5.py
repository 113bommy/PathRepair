def spam(a):
    r = 0
    for c in str(a):
        r += int(c)
    return r

a, b, c = map(int, input().split())
r = []
s = 1
for s in range(1, 82):
    x = b*s**a + c
    if x > 0 and s == spam(x):
        r += [str(x)]
print(len(r))
print(" ".join(r))
