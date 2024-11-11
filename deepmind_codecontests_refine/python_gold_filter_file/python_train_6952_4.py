import sys
input=lambda: sys.stdin.readline().rstrip()
A=input()
B=input()
C=input()

a,b,c=len(A),len(B),len(C)

def f(X,Y):
  XY=[True]*(10**4)
  x,y=len(X),len(Y)
  for i in range(5000-y+1,5000+x):
    ret=True
    if i<=5000:
      for j in range(min(x,y+i-5000)):
        if X[j]=="?" or Y[j-i+5000]=="?" or X[j]==Y[j-i+5000]:
          continue
        else:
          ret=False
    else:
      for j in range(min(y,x-i+5000)):
        if Y[j]=="?" or X[j+i-5000]=="?" or Y[j]==X[j+i-5000]:
          continue
        else:
          ret=False
    XY[i]=ret
  return XY
AB=f(A,B)
BC=f(B,C)
AC=f(A,C)
ans=a+b+c
for i in range(5000-b-c,5000+a+c):
  if AB[i]:
    for j in range(5000-b-c,5000+a+b):
      if -4000<=j-i<=4000:
        if AC[j] and BC[j-i+5000]:
          l=min(5000,i,j)
          r=max(i+b,j+c,5000+a)
          ans=min(ans,r-l)
      else:
        if AC[j]:
          l=min(5000,i,j)
          r=max(i+b,j+c,5000+a)
          ans=min(ans,r-l)
print(ans)
