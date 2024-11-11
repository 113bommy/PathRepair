n,p,k=[int(i) for i in input().split()]
a=(2*k+1)*[0]
z=p-k
for i in range(2*k+1):
    a[i]=z+i
b=a[:]
#print(len(b),len(a))
for i in range(2*k,-1,-1):
    #print(len(a))
    #print(i)
    if a[i]<1 or a[i]>n:
        b.pop(i)
#print(b)
z='('+str(p)+')'
z2=b.index(p)
x=''
print(z2)
if 1 not in b:
    x+='<< '
for i in range(z2):
    x+=str(b[i])+' '
x+=z+' '
if n  not in b:
    for i in range(z2+1,len(b)):
        x+=str(b[i])+' '
    x+='>>'
else:
    for i in range(z2+1,len(b)):
        x+=str(b[i])+' '
print(x)
