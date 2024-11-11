def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
[n,p]=i2()
s=input()

  
if p==2 or p==5:
   x1=0
   for i in range(n):
     if int(s[i])%p==0:
        x1+=i+1  
   print(x1)
else:
  t=0
  x2=0
  d={0:1}
  a=1
  for i in range(n)[::-1]:
     t+=int(s[i])*a
     t%=p
     a*=10
     a%=p
     if t in d:
        x2+=d[t]
        d[t]+=1
     else:
        d[t]=1
  print(x2)