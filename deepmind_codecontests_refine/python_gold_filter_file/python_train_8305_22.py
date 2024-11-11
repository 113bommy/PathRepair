N = int(input())
*P, = map(int, input().split())

N += 1
data = [0]*(N+1)
def add(k, x):
    while k <= N:
        data[k] += x
        k += k & -k

def get(k):
    s = 0
    while k:
        s += data[k]
        k -= k & -k
    return s

N0 = 2**(N-1).bit_length()
def lower_bound(x):
    w = i = 0
    k = N0
    while k:
        if i+k <= N and w + data[i+k] <= x:
            w += data[i+k]
            i += k
        k >>= 1
    return i+1

E = [(v, i) for i, v in enumerate(P)]
E.sort(reverse=1)

add(1, 1)
add(N+1, 1)

ans = 0
for v, i in E:
    k = get(i+2)
    l1 = lower_bound(k-2)
    l0 = lower_bound(k-1)
    r0 = lower_bound(k)
    r1 = lower_bound(k+1)
    if l0 > 1:
        ans += (l0-l1) * (r0 - (i+2)) * v
    if r0 < N+2:
        ans += (r1-r0) * (i+2 - l0) * v
    add(i+2, 1)
print(ans)