r1,c1,r2,c2=map(int,input().split())
MOD=10**9+7
idx=r2+c2+2
perm=[1]*(idx+1)
perm_inv=[1]*(idx+1)
for i in range(1,idx+1):
    perm[i]=perm[i-1]*i
    perm[i]%=MOD
def inv_mod(a):
  return pow(a,MOD-2,MOD)
perm_inv[-1]=inv_mod(perm[-1])
for i in range(idx-1,-1,-1):
    perm_inv[i]=perm_inv[i+1]*(i+1)
    perm_inv[i]%=MOD
def comb(i,j):
    buf=perm[i+j+2]
    buf*=perm_inv[i+1]
    buf%=MOD
    buf*=perm_inv[j+1]
    buf%=MOD
    return buf
res=comb(r2,c2)
res-=comb(r2,c1-1)
res-=comb(r1-1,c2)
res+=comb(r1-1,c1-1)
print(res)