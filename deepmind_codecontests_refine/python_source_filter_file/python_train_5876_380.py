import sys
x=str(input())
y=str(input())
p=len(x)
q=len(y)
z=0
if p==q:
  for i in range(p):
     if x[i]==y[p-i-1]:
        z=1
     else:
        print('No')
        sys.exit(0)
if z==1:
    print('Yes')
elif p!=q:
    print('No')