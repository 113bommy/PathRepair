n=int (input())
a = list(input().split())
y=[]
z=[]
for i in range(len(a)):
    if a[i]=='5':
        y.append(int (a[i]))
    else:
        z.append(int (a[i]))
if len(z)>0:
    k=True
    i=len(y)-1
    d=0
    while k==True and i>=0:
        c=[]
        for j in range(i+1):
            c.append(str (y[j]))
        b=''.join(c)
        b=int (b)
        if b%9==0:
            k=False
            d=b
        i=i-1
    if d>0:
        print(d,end="")
        for i in range(len(z)):
            print(z[i],end="")
    else:
        print(0)
else:
    print(-1)