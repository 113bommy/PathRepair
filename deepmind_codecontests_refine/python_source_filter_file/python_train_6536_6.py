r1,c1,r2,c2=map(int,input().split())
MOD=10**9+7
idx=r2+c2+3
perm=[1]*(idx+1)
for i in range(1,idx+1):
    perm[i]=perm[i-1]*i
    perm[i]%=MOD
def inv_mod(a):
  return pow(a,MOD-2,MOD)

def comb(n,m,p=10**9+7):
    if n < m : return 0
    if n < 0 or m < 0:return 0
    m = min(m, n-m)
    top = bot = 1
    for i in range(m):
        top = top*(n-i) % p
        bot = bot*(i+1) % p
    bot = pow(bot, p-2, p)
    return top*bot % p
def g(i,j):
    return comb(i+j+2,i+1,MOD)
def s(n,m):
    return comb(n+m+2, m+1, MOD)
res=g(r2,c2)-g(r2,c1-1)-g(r1-1,c2)+g(r1-1,c1-1)


ans = s(r2,c2) - s(r2, c1-1) - s(r1-1, c2) + s(r1-1, c1-1)
ans %= MOD
print(res)