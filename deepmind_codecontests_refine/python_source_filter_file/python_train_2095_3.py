import sys

def binsearch(x, arr):
    s = 0
    e = len(arr) - 1
    l = len(arr)

    if x < arr[s]:
        return s
    if x > arr[e]:
        return e

    while e - s > 4:
        m = (s + e)//2
        if arr[m] < x:
            s = m + 1
        else:
            e = m - 1

    s = max(0, s-1)
    e = min(e+1, l-1)

    mint = 100000 + 5
    idx = -1
    for t in range(s, e+1):
        dist = abs(arr[t] - x)
        if dist < mint:
            mint = dist
            idx = t
    return idx

if __name__ == "__main__":

    ns, ms = sys.stdin.readline().strip().split()

    n = int(ns)
    m = int(ms)

    pos = [int(s) for s in sys.stdin.readline().strip().split()]
    roles = [int(s) for s in sys.stdin.readline().strip().split()]

    d = []
    r = []

    for p, role in zip(pos, roles):
        if role == 1:
            d.append(p)
        else:
            r.append(p)

    cnt = [0] * m

    for p in r:
        idx = binsearch(p, d)
        cnt[idx] += 1

    print(" ".join([str(i) for i in cnt]))
