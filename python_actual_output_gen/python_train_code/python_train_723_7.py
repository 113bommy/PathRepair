a=int(input())
b=[int(x) for x in input()]
c=sum(b)
e=[]
for i in range(2,len(b)):
    if c%i==0:
        e.append(i)
d=False
for i in e:
    r=[]
    b1=b[:]
    num=c//i
    k=0
    while b1:
        k+=b1[0]
        b1=b1[1:]
        if k==num:
            r.append(k)
            k=0
        elif k>num:
            break
        if len(r)==i:
            d=True   
if d:
    print('YES')
else:
    print('NO')
    