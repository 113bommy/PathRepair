import sys

# sys.setrecursionlimit(200005)
int1 = lambda x: int(x)-1
pDB = lambda *x: print(*x, end="\n", file=sys.stderr)
p2D = lambda x: print(*x, sep="\n", end="\n\n", file=sys.stderr)
def II(): return int(sys.stdin.readline())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LLI1(rows_number): return [LI1() for _ in range(rows_number)]
def SI(): return sys.stdin.readline().rstrip()
# inf = 18446744073709551615
inf = 4294967295
# md = 10**9+7
md = 998244353

def nCr(com_n, com_r):
    if com_r < 0: return 0
    if com_n < com_r: return 0
    return fac[com_n]*ifac[com_r]%md*ifac[com_n-com_r]%md

n_max = 5005
fac = [1]
for i in range(1, n_max+1): fac.append(fac[-1]*i%md)
ifac = [1]*(n_max+1)
ifac[n_max] = pow(fac[n_max], md-2, md)
for i in range(n_max-1, 1, -1): ifac[i] = ifac[i+1]*(i+1)%md

n, k = LI()
aa = list(map(int, SI()))
if k == 0 or aa.count(1) < k:
    print(1)
    exit()

aa.append(1)
s = 0
r = -1
while r+1 < n and s <= k:
    r += 1
    s += aa[r]
f = 0
while f < n and aa[f] == 0: f += 1
ans = nCr(r, s-1)-nCr(r-f-1, s-2)+1
ans %= md
# pDB(r, f, s, ans)

for i, a in enumerate(aa):
    if a:
        l = i+1
        f = l
        while f < n and aa[f] == 0: f += 1
        s -= 1
        while r+1 <= n and s <= k:
            r += 1
            s += aa[r]
        if s == 1: break
        ans += nCr(r-l, s-1)-nCr(r-f-1, s-2)
        ans %= md
        # pDB(l, r, s, ans)
print(ans)
