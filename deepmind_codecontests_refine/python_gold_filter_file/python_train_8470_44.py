def by(x): # x is int
    lx = list(str(x))
    sx = set(str(x))
    if len(lx) == len(sx):
        return 1

def nby(x):
    t = x+1
    while by(t) != 1:
        t += 1
        continue
    return t

y = int(input())
print(nby(y))
