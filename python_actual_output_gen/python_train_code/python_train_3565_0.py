def build_fac():
   global mod
   fac = [1] * int(2e5 + 1)
   for i in range(1, int(2e5)):
      fac[i] = i*fac[i-1] % mod
   return fac

def inv(x):
   global mod
   return pow(x, mod-2, mod)

def ncr(n, r):
   global fac
   if n < 0 or n < r: return 0
   return fac[n]*inv(fac[r])*inv(fac[n-r]) % mod

def cf(f, w, h):
   global mod
   if w == 0: return 1
   rs = 0
   for k in range(1, min(w//(h+1),f+1)+1):
      rs += ncr(f+1, k) * ncr(w-k*h-1, k-1) % mod
      rs %= mod
   return rs

f, w, h = map(int,input().split(' '))
mod = int(1e9 + 7)

fac = build_fac()
cnt = cf(f, w, h)
rs = cnt*inv(ncr(f+w, w)) % mod

print(rs)