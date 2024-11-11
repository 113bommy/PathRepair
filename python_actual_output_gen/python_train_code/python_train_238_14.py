y,k,n=map(int,input().strip().split(' '))
s=n-y
x=k-y%k
a=0
while x<s:
  print(x,end=' ')
  x=x+k
  a=1
if a==0:
  print(-1)