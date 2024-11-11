mod=10**9+7
n=int(input())
T=[int(i) for i in input().split()]
A=[int(i) for i in input().split()]
Tres=[0]*n
Ares=[0]*n
Tres[0]=[0,T[0]]
Ares[-1]=[0,A[-1]]
for i in range(1,n):
  if T[i]>T[i-1]:
    Tres[i]=[0,T[i]]
  else:
    Tres[i]=[1,T[i]]
  if A[-i-1]>A[-i]:
    Ares[-i-1]=[0,A[-i-1]]
  else:
    Ares[-i-1]=[1,A[-i-1]]
ans=1
for i in range(n):
  ta,tb=Tres[i]
  aa,ab=Ares[i]  
  if ta==1 and aa==1:
    ans*=min(tb,ab)%mod
  elif ta==0 and aa==1 and tb>ab:
    ans=0
  elif ta==1 and aa==0 and tb<ab:
    ans=0
  elif ta==0 and aa==0 and tb!=ab:
    ans=0
print(ans%mod)
