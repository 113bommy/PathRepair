mod=10**9+7
n=int(input())
T=[int(i) for i in input().split()]
A=[int(i) for i in input().split()]
Tres=[0]*n
Ares=[0]*n
Tres[0]=(0,T[0])
Ares[n-1]=(0,A[n-1])
for i in range(1,n):
  if T[i]>Tres[i-1][1]:
    Tres[i]=(0,T[i])
  else:
    Tres[i]=(1,T[i])
  if A[n-i-1]>Ares[n-i][1]:
    Ares[n-i-1]=(0,A[n-i-1])
  else:
    Ares[n-i-1]=(1,A[n-i-1])
if Tres[0]<=Ares[0]:
  ans=1
else:
  ans=0
for i in range(1,n):
  ta,tb=Tres[i]
  aa,ab=Ares[i]  
  if ta==aa==1:
    ans=ans*min(tb,ab)%mod
  elif ta==0 and aa==1 and tb>ab:
    ans=0
  elif ta==1 and aa==0 and tb<ab:
    ans=0
  elif ta==0 and aa==0 and tb!=ab:
    ans=0
print(ans%mod)