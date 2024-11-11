a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
c={}
for i in range(a[1]):
    c[i]=[]
for i in range(a[0]):
    d=b[i]%a[1]
    c[d].append(b[i])
e=0
e+=(len(c[0])//2)*2
if a[1]%2==0:
    e+=(len(c[a[1]//2])//2)*2
if a[1]%2==0:
    for i in range(1,a[1]//2):
        e+=2*min(len(c[i]),len(c[a[1]-1]))
else:
    for i in range(1,a[1]//2+1):
        e+=2*min(len(c[i]),len(c[a[1]-i]))
print(e)