x=[c for c in input()]
x.sort()
p=len(x)
x.append('0')
k=0
a=[]
b=[]
y=['0']*p
while k<p:
    if x[k]==x[k+1]:
        a.append(x[k])
        k+=2
    else:
        b.append(x[k])
        k+=1
a=sorted(a+b[:(len(b)//2)])
for i in range(len(a)):
    y[i]=a[i]
    y[-1-i]=a[i]
if p%2==1:
    y[(p-1)//2]=b[(len(b)-1)//2]
print(''.join(y))
