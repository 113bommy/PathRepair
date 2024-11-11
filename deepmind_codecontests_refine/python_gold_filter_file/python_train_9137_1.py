N,P = map(int,input().split())
lst=[int(d) for d in input()]
chk=[0]*P
t=0
c=1
if P==2:
 ans=0 
 a=N
 for x in lst[::-1]:
  if x%2==0:
   ans+=a
  a-=1
 print(ans)
elif P==5:
 ans=0 
 a=N
 for x in lst[::-1]:
  if x%5==0:
   ans+=a
  a-=1  
 print(ans)
else:
 for x in lst[::-1]:
  t+=c*x
  t%=P
  chk[t]+=1
  c*=10
  c%=P 
 md=0
 ans=chk[0]
 d=1
 for i in range(N-1):
  md=(md+lst[N-1-i]*d)%P
  if chk[md]>0:
   chk[md]-=1
  ans+=chk[md]
  d*=10
  d%=P
 print(ans)
