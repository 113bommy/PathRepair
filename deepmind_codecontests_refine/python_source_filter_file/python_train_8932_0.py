lines = []
def fi(i, x):
    a, b = lines[i]
    return a*x+b

def find(x):
    def f(i):
        return fi(i+1,x) > fi(i,x)
    mn, mx = -1, len(lines)-1
    idx = (mn+mx)//2
    while mx-mn>1:
        if f(idx):
            mx, idx = idx, (mn + idx)//2
            continue
        mn, idx = idx, (mx + idx)//2
    return fi(idx+1, x)

def find2(x):
    # x が単調増加
    I = find2.I
    u, v = lines[I]
    while I+1<len(lines):
        w, y = lines[I+1]
        if u*x+v < w*x+y:
            break
        u, v = w, y
        I += 1
    find2.I = I
    return u*x+v
find2.I = 0

def insert(a, b):
    pass

def insert2(a, b):
    # a が単調減少
    if not lines:
        lines.append((a,b))
        return
    (e, f) = lines[-1]
    while len(lines)-1:
        (c, d), (e, f) = (e, f), lines[-2]
        if (c-e)*(b-d) < (d-f)*(a-c):
            break
        lines.pop()
    lines.append((a, b))

N, C = map(int, input().split())
hs = map(int, input().split())
r = 0
lines = []
for i, h in enumerate(hs):
    if i!= 0:
        r = fi(find(h), h) + h**2+C
    insert(-2*h, r+h**2)
print(r)
