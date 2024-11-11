from math import gcd
from functools import reduce
def osa_k(n=10**6):
  p=list(range(n+1))
  for i in range(2,int(n**.5)):
    if p[i]<i:continue
    for j in range(i*i,n+1,i):
      if p[j]==j:p[j]=i
  return p
def fact_o(n):
  a=[]
  f=0
  while n>1:
    if f!=p[n]:ans[p[n]]+=1
    f=p[n]
    n//=p[n]
  return 0
p=osa_k()
n=int(input())
a=list(map(int,input().split()))
ans=[0]*(10**6+1)
for i in a:
  fact_o(i)
if max(ans)==1:print('pairwise coprime')
elif reduce(gcd,a)==1:print('setwise coprime')
else:print('not coprime')