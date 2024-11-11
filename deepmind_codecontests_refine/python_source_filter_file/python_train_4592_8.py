t=int(input())
for _ in range(t):
 a,b=map(int,input().split());f=1;n=a+b;i=2
 while i*i<=n:
  if n%i==0:break
  i+=1
 else:f=0
 print('YNEOS'[a-b>1or f])