from fractions import gcd
N.M=(int(i) for i in input.split())
S=input()
T=input()
gcd_NM=gcd(N,M)
lcm_NM=(N*M//gcd_NM)
A=True
for i in range(gcd_NM):
  if S[(N//gcd_NM)*i]!=T[(M//gcd_NM)*i]:
    A=False 
    break
if A:
  print(lcm_NM)
else:
  print(-1)