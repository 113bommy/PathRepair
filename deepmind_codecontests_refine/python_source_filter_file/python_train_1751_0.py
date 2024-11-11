import sys
readline = sys.stdin.readline

def f(a, b):
    return (1+(-(-a//b)-1).bit_length())//2

N = int(readline())
A = list(map(int, readline().split()))

dpr = [0]*N
Ar = A[:]
cnt = 0
for i in range(1, N):
    res = 0
    idx = i-1
    while cnt <= idx:
        k = f(Ar[idx+1], Ar[idx])
        if k:
            Ar[idx] *= 4**k
            res += k
        idx -= 1
        if not k:
            break
    else:
        dpr[i] += cnt
    dpr[i] += dpr[i-1] + res
    while cnt < i:
        if Ar[cnt] < Ar[cnt+1]*4:
            cnt += 1
        else:
            break

dpl = [0]*N
Al = A[:]
cnt = N-1
for i in range(N-2, -1, -1):
    res = 0
    idx = i+1
    while cnt >= idx:
        k = f(Al[idx-1], Al[idx])
        if k:
            Al[idx] *= 4**k
            res += k
        idx += 1
        if not k:
            break
    else:
        dpl[i] += N-1-cnt
    dpl[i] += dpl[i+1] + res
    while cnt > i:
        if Al[cnt] < Al[cnt-1]*4:
            cnt -= 1
        else:
            break
dpl = [2*dpl[i] for i in range(N)]
dpr = [0] + [i+1+2*dpr[i] for i in range(N)]
inf = 10**20
ans = inf
for i in range(N):
    ans = min(ans, dpr[i] + dpl[i])
print(ans)