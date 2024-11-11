def mul(L, x):
    m = []
    for y in L:
        m += [x*y]
    return m
def diff(a, b):
    d=0
    for i, j in zip(a,b):
        d+= j-i if j-i < 0 else 0
    return d

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
high = 1002
low = 0
while low <= high:
    mid = (low+high)//2
    d = diff(mul(a, mid), b)
    here = False
    if k+d == 0:
        break
    elif k+d < 0:
        here = True
        high = mid -1
    else:
        low = mid + 1
print(mid if not here else high)