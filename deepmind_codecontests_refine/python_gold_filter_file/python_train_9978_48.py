from collections import Counter, deque, defaultdict
def inpl(): return list(map(int, input().split()))

MOD = 10**9 + 7
def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod
 
size = 2*10**5 + 1
g1, g2, inverse = [0]*size, [0]*size, [0]*size
 
g1[:2] = [1, 1] # 元テーブル
g2[:2] = [1, 1] #逆元テーブル
inverse[:2] = [0, 1] #逆元テーブル計算用テーブル
 
for i in range(2, size):
    g1[i] =  ( g1[i-1] * i ) % MOD 
    inverse[i] = (-inverse[MOD % i] * (MOD//i) ) % MOD 
    g2[i] =  (g2[i-1] * inverse[i]) % MOD


N = int(input())
A = inpl()
C = Counter(A)
for k, v in C.items():
    if v == 2:
        break
l = A.index(k)
r = N - A[::-1].index(k)

d = r - l - 1

print(N)
print((1 + N-1 + d + cmb(N-1, 2, MOD))%MOD)
for k in range(3, N+2):
    X = cmb(N-1, k-1, MOD)
    Y = cmb(N-1-d, k-1, MOD)
    Z = X - Y
    tmp = cmb(N-1, k, MOD) + Y + 2*Z + cmb(N-1, k-2, MOD)
    print(tmp%MOD)