n,k=map(int,input().split())
A=list(map(int,input().split()))
mod=10**9+7
A.sort()
def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod
N = 10**4
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル
for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )
ans,bns=0,0
for j in range(n-k+1):
  ans=(ans+(A[n-j-1]-A[j])*cmb(n-j-1,k-1,mod))%mod
print(ans%mod)