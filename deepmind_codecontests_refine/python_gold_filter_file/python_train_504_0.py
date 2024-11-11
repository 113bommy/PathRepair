while 1:
 a={};b=1
 n=int(input())
 if n==0:break
 for _ in[0]*n:
  e,p,q=map(int,input().split())
  a.setdefault(e,0);a[e]+=p*q
 for e in a:
  if a[e]>=1e6:print(e);b=0
 if b:print('NA')
