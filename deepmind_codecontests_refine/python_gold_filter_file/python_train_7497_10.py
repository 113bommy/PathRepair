dat = [0] * 400000
m = 0

def init():
    global dat, m
    for i in range(2 * m - 1):
        dat[i] = 0

def add(i, x):
    global dat, m
    i += m - 1
    dat[i] += x
    while i > 0:
        i = (i - 1) // 2
        dat[i] = dat[2 * i + 1] + dat[2 * i + 2]

def getSum(a, b, k, l, r):
    global dat, m
    if r <= a or b <= l:
        return 0
    if a <= l and r <= b:
        return dat[k]
    else:
        vl = getSum(a, b, 2 * k + 1, l, (l + r) // 2)
        vr = getSum(a, b, 2 * k + 2, (l + r) // 2, r)
        return vl + vr

n, q = map(int, input().split())
m = 1
while m < n:
    m *= 2

for _ in range(q):
    com, x, y = map(int, input().split())
    if com == 0:
        add(x - 1, y)
    else:
        print(getSum(x - 1, y, 0, 0, m))
