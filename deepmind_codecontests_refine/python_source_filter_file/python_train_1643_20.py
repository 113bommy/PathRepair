n=int(input())
x=input()
import sys
sys.setrecursionlimit(10**7)
if n==1:
  print(1 if x=='1' else 0)
  exit()
def pc(x):
  a=bin(x)[2:]
  return a.count('1')
def func(x):
  if x==0:
    return 0
  else:
    return func(x%pc(x))+1
pcx=x.count('1')
if pcx==0:
  for _ in range(n):
    print(1)
else:
  x0,x1=0,0
  for i in range(n):
    if x[i]=='1':
      if pcx!=1:
        x0+=pow(2,n-1-i,pcx-1)
        x0%=pcx-1
      x1+=pow(2,n-1-i,pcx+1)
      x1%=pcx+1
  for i in range(n):
    ans=0
    if x[i]=='1':
      if pcx==1:
        print(0)
      else:
        xx=x0-pow(2,n-1-i,pcx-1)
        xx%=pcx-1
        print(func(xx)+1)
    else:
      xx=x1+pow(2,n-1-i,pcx+1)
      xx%=pcx+1
      print(func(xx)+1)
