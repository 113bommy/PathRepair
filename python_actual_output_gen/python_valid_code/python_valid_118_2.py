A=[]
B=[]
a=0
x=0
for c in input():
 if"\\"==c:A+=[x]
 elif"/"==c and A:
  j=A.pop()
  t=x-j
  a+=t
  while B and B[-1][0]>j:t+=B[-1][1];B.pop()
  B+=[(j,t)]
 x+=1
print(a)
if p:print(len(B),*list(zip(*B))[1])
else:print(0)
