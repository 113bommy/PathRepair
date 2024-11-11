n=int(input())
a=list(input())
b=list(input())
aa=a.__len__()
bb=b.__len__()
print(aa,bb)
x=y=0
t=min(n,aa*bb)
a=a*bb
b=b*aa
for i in range(t):
    if a[i]=="R":
        if b[i]=="S":
            x+=1
        elif b[i]=="P":
            y+=1
    if a[i]=="S":
        if b[i]=="P":
            x+=1
        elif b[i]=="R":
            y+=1
    if a[i]=="P":
        if b[i]=="R":
            x+=1
        elif b[i]=="S":
            y+=1
#print(aa,bb)
if aa*bb>=n:
    print(y,x)
else:
    delta=n%(aa*bb)
    count=n//(aa*bb)
    xx=yy=0
    for i in range(delta):
        if a[i]=="R":
            if b[i]=="S":
                xx+=1
            elif b[i]=="P":
                yy+=1
        if a[i]=="S":
            if b[i]=="P":
                xx+=1
            elif b[i]=="R":
                yy+=1
        if a[i]=="P":
            if b[i]=="R":
                xx+=1
            elif b[i]=="S":
                yy+=1
    print(y*count+yy,x*count+xx)