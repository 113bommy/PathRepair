mod = 10**9+7
k = int(input())
s = input()

def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, len(s)+k+5):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

ans = 0
for i in range(len(s), len(s)+k+1):
  ans += pow(25, i-len(s), mod)*pow(26, k+len(s)-i, mod)*cmb(i-1, len(s)-1, mod)
  ans %= mod
  
print(ans)