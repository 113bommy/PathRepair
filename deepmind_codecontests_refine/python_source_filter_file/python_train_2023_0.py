m = 1000000007
a, b, c = 1, 0, 1
for s in input():
    if s == '*': a, b, c = 0, b + c, 0
    elif s == '?': a, b, c = (a + b) % m, (b + c) % m, b % m
    elif s == '0': a, b, c = a, 0, 0
    elif s == '1': a, b, c = b, 0, a
    else: a, b, c = 0, 0, b
print((a + b) % m)