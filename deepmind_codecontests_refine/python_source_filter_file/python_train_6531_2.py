x=str(input())
x=x.split(' ')
x=[int(g) for g in x if g!='']
l=str(input())
c=0
t=0
f=l[0]
for i in range(x[0]):
    if(f!=l[i]):
       f=l[i]
       c+=1
if(c!=0):
    t=1
if(f==l[x[0]-1]):
    if(f=='0'):
        k=(c+2)/2
    if(f=='1'):
        k=c/2
else:
    k=(c+1)/2
if(t==1):
    if(x[1]<x[2]):
        print(int((k-1)*x[1]+x[2]))
    else:
        print(int(k*x[2]))
else:
    if(f=='0'):
        print(x[2])
    else:
        print(0)
