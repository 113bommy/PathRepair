n=int(input())
s=str(n)+" :"
b=True
d=n
i=2
while b:
 if d%i==0:
  d/=i
  s+=' '+str(i)
  i-=1
 b=i<d**0.5
 i+=1
if d!=1:s+=' '+str(d)
print(s)