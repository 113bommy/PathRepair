from math import gcd
def evc(a, b):
    if a == 0:
        return [0, 1, b]
    x, y, g = evc(b % a, a)
    return [y - (b // a) * x, x, g]
    
a, b, c = map(int, input().split())
cur = evc(a, b)
if c % cur[2]:
    print(-1)
else:
    k = -c // cur[2]
    print(cur[0] * k, cur[1] * k)