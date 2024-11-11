S=str(input())
T=str(input())
ls=len(S)
lt=len(T)
m=0
for i in range(ls-lt+1):
  A=S[i:i+lt]
  a=0
  for s,t in zip(A,T):
    if s==t:
      a+=1
  m=max(m,a)
print(lt-m)