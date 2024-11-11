import math
import sys
import fractions
inp = input()
N,A,B,K = list(map(int,inp.split()))
# g = math.gcd(A,B)
g = fractions.gcd(A,B)
if K % g != 0:
    print(0)
    sys.exit()
A = A // g
B = B // g
K = K // g
xn = []
yn = []
for i in range(10 ** 100):
    if (A * i- K) % B == 0:
        n = i
        xn.append(n)
        yn.append((K - A *n) // B)
        break
if yn[-1] < 0:
    if K % B == 0 and (K // B <= N):
        print(1)
    else:
        print(0)
    sys.exit()
while True:
    x  = xn[-1] + B
    y  = yn[-1] - A
    if y < 0:
        break
    xn.append(x)
    yn.append(y)
ans = 0
P = 998244353
def inv(n):
  return pow(n, P-2, P)
fact = [1] * (N+1)
for i in range(1, N+1):
  fact[i] = fact[i-1] * i % P
invfact = [inv(fact[N])] * (N+1)
for i in range(N, 0, -1):
  invfact[i-1] = invfact[i] * i % P
def comb(n, k):
  return fact[n] * invfact[k] * invfact[n-k] % P 
 
for x,y in zip(xn,yn):
    if N-x< 0 or N -y < 0:
        continue 
    ans = (ans + (comb(N,x) * comb(N,y))) % P
print(ans)