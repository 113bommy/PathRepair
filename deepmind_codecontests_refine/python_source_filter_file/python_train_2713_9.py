def update(i, x):
    i += base
    st[i] = x
    while i>0:
        i//=2
        st[i] = min(st[i*2+1], st[i*2+2])


def find(a, b):
    return _find(a, b+1, 0, 0, n)


def _find(a, b, k, l, r):
    if b <= l or r <= a:
        return 2**31-1

    if a <= l and r <= b:
        return st[k]

    rl = _find(a, b, 2*k+1, l, (l+r)/2)
    rr = _find(a, b, 2*k+2, (l+r)/2, r)
    return min(rl, rr)


(_n, q) = map(int, input().split())

n=1
while(n<=_n):
    n *= 2
base = n-1
st = [2**31-1]*(2*n-1)

for i in range(q):
    (c, l, r) = map(int, input().split())
    if c:
        print(find(l, r))
    else:
        update(l, r)