import sys
from itertools import permutations
from random import randrange
readline = sys.stdin.readline

mod = 10**9+9
base = 2009   
def rollinhash(S):
    N = len(S)           
    has = 0
    for i in range(N):
        s = S[i]
        has = (has*base + s)%mod
    return has

phr = []
while len(set(phr)) != 26:
    phr = [randrange(1, 10**9) for _ in range(26)]
def shash(S):
    N = len(S)            
    has = 0
    for i in range(N):
        has = has + phr[S[i]]*phr[S[N-1-i]]
    return has

H, W = map(int, readline().split())
G = [list(map(ord, readline().strip())) for _ in range(H)]

ans = 'NO'
fh = H//2
ch = H-fh
lir = list(range(H))
seen = set()
for k in permutations(lir, ch):
    k = list(k)
    sk = set(k)
    for i in range(H):
        if i not in sk:
            k.append(i)
    
    sh = shash(k)
    if sh in seen:
        continue
    seen.add(sh)
    
    
    G2 = []
    for j in k:
        G2.append(G[j])
    G2 = list(map(list, zip(*G2)))
    G2h = [rollinhash(g) for g in G2]
    G2hi = [rollinhash(g[::-1]) for g in G2]
    
    used = [False]*W
    w1 = 0
    match = W//2
    while match and w1 < W:
        if used[w1]:
            w1 += 1
            continue
        sa = G2hi[w1]
        for w2 in range(w1+1, W):
            if used[w2]:
                continue
            if G2h[w2] == sa:
                used[w1] = True
                used[w2] = True
                match -= 1
                break
        w1 += 1
    if sum(used) >= W-1:
        if sum(used) == W-1:
            mid = used.index(False)
            if G2h[mid] == G2hi[mid]:
                ans = 'YES'
        else:
            ans = 'YES'
    if ans == 'YES':
        break
print(ans)