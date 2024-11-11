N = int(input())
src = list(map(int,input().split()))

cands = list(sorted(set(src)))

def enough(i):
    bit = [0] * (2*N+10)
    def bit_add(a,w):
        x = a
        while x <= (2*N+9):
            bit[x] += w
            x += (x & -x)
    def bit_sum(a):
        x = a
        ret = 0
        while x > 0:
            ret += bit[x]
            x -= (x & -x)
        return ret

    cums = [0]
    for a in src:
        tmp = 1 if a >= cands[i] else -1
        cums.append(cums[-1] + tmp)

    cnt = 0
    for i in range(N+1):
        a = cums[i] + N+5
        cnt += bit_sum(a)
        bit_add(a, 1)
    return cnt*2 >= N*(N+1)//2

ok = 0
ng = len(cands)
while ng - ok > 1:
    m = (ok+ng)//2
    if enough(m):
        ok = m
    else:
        ng = m
print(cands[ok])