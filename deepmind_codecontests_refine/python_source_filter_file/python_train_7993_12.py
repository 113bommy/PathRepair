od = 10**9+7
def comb(n, k):
    c = 1
    for i in range(k):
        c *= n - i
        c %= mod
    d = 1
    for i in range(1, k + 1):
        d *= i
        d %= mod
    return (c * pow(d, mod - 2, mod)) % mod
x,y=map(int,input().split())

ans=0

z=x//2+1

for q in range(z,x+1):
  w=2*q-x
  if w*2+(q-w)==y:
    t=comb(q,w)
    ans+=t
    
  
  
print(ans)