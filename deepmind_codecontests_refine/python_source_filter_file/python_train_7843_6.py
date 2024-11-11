from math import sqrt, floor

x = int(input())

ans = 0

ds = set()

l = floor(sqrt(x))

for d in range(1, l):
    if x % d == 0:
        ds.add(d)
        ds.add(x // d)

x = str(x)

def check(d):
    d = str(d)
    for c in d:
        if c in x:
            return True
    return False

print(sum(map(check, ds)))

