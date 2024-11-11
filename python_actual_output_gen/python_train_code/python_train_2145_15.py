S=str(input())
T=str(input())
ls=len(S)
lt=len(T)
m=0
for i in range(ls):
  A=S[i:lt]
  a=0
  for s,t in zip(A,T):
    if s==t:
      a+=1
  m=max(m,a)
print(lt-m)