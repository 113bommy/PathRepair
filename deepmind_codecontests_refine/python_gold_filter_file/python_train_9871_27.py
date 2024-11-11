N = int(input())
h = [int(x) - 1 for x in input().split()]
a = [int(x) for x in input().split()]

l2N = 0
n = N
while n > 1:
    n = -(-n//2)
    l2N += 1
N = 2**l2N

seg = [0] * (2 * 2**l2N - 1)

def update(H, x):
    H += 2**l2N - 1
    seg[H] = x
    while H > 0:
        H = (H - 1) // 2
        seg[H] = max(seg[H*2+1], seg[H*2+2])

def maxSrch(a, b, k, l, r):
    if r <= a or b <= l:
        return 0
    if a <= l and r <= b:
        return seg[k]
    else:
        vl = maxSrch(a, b, k*2+1, l, (l+r)//2)
        vr = maxSrch(a, b, k*2+2, (l+r)//2, r)
        return max(vl, vr)

for H,A in zip(h,a):
    update(H, maxSrch(0,H,0,0,N) + A)
print(seg[0])