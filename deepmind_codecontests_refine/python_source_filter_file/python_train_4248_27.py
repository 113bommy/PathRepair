N= int(input())
if N%2==1:
 print(0)
else:
 a=0
 i=0
 while (5**i)*2<=N:
  i+=1
  b=(5**i)*2
  a+=(N//b)
print(a)