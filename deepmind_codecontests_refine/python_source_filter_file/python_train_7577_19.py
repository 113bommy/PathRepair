from math import*
M=10**9+7
n=int(input())
s=input()
if s[0]==s[-1]=='W':
  print(0)
  exit()
l=a=1
r=f=0
for b,c in zip(s,s[1:]):
  if b==c:
    f^=1
  if f:
    a*=r-l
    a%=M
    r+=1
  else:
    l+=1
print(a*factorial(n)%M*(l==r))