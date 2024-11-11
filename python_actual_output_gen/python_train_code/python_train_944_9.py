N, A, B = map(int, input().split())
h = [int(input()) for _ in range(N)]
h.sort()


def isOk(k):
    return k >= 0


ok, ng = max(h)//B+1, 1
while abs(ok-ng) > 1:
    mid = (ok+ng)//2
    c = mid
    for i in range(N):
        t = h[i]-mid*B
        if t > 0:
            c -= (t+A-B-1)//(A-B)
            if c < 0:
                break
    if isOk(c):
        ok = mid
    else:
        ng = mid

print(ok)