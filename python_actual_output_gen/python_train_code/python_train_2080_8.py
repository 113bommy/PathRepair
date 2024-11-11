from itertools import chain

h, w = map(int, input().split())

def f(x, h, w):
    h2 = h // 2
    h3 = h - h2
    a,b,c = sorted((x,w*h2,w*h3))
    w2 = w // 2
    w3 = w - w2
    d,e,f = sorted((x,w2*h,w3*h))
    return min(c-a, f-d)

ss = ((w2*h, h, w-w2) for w2 in range(1, (w+1)//2))
ts = ((w*h2, h-h2, w) for h2 in range(1, (h+1)//2))

print(min(f(*xs) for xs in chain(ss, ts)))