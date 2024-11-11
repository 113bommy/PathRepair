def check(ccc, ddd, e, ans):
    m = 2147483647
    g = 1000000007
    for l in range(e):
        cl = ccc[l]
        if any(c != cl for c in ccc[l::e]):
            return
        dl = ddd[l]
        if any(d != dl for d in ddd[l::e]):
            return
    s = 0
    for c in ccc[:e]:
        s = (s * g + c) % m
    t = 0
    for d in ddd[:e]:
        t = (t * g + d) % m
    u = pow(g, e, m)
    for h in range(e):
        if s == t:
            bh = bbb[h]
            ans.update(((i - h) % n, aaa[i] ^ bh) for i in range(0, n, e))
            return
        t = (t * g + ddd[(e + h) % n] - ddd[h] * u) % m


def solve(n, aaa, bbb):
    ccc = [a1 ^ a2 for a1, a2 in zip(aaa, aaa[1:])] + [aaa[-1] ^ aaa[0]]
    ddd = [b1 ^ b2 for b1, b2 in zip(bbb, bbb[1:])] + [bbb[-1] ^ bbb[0]]

    ans = set()

    e = 1
    while e * e <= n:
        if n % e != 0:
            e += 1
            continue
        check(ccc, ddd, e, ans)
        check(ccc, ddd, n // e, ans)
        e += 1

    return ans


n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
ans = solve(n, aaa, bbb)
print(''.join('{} {}\n'.format(*answer) for answer in sorted(ans)))
