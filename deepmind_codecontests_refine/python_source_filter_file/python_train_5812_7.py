I=lambda:map(int,input())
n,k=I()
s=1001
for i in range(n):
  a,b=I()
  if b<=k:
    s=min(s,a)
if s==1001:
  print('TLE')
else:
  print(s)