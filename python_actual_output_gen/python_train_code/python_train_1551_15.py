N,M = map(int,input().split())
 
s = 0
 
for i in range(K,N+2):
  s += i*N +1 - i*(i -1)

print(s%(10**9 +7))