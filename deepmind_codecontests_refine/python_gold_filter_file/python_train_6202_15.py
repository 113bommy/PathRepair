ch1=input()
ch2=input()
ch3=input()
t1=[]
t2=[]
t3=[]
t1=ch1.split(' ')
t2=ch2.split(' ')
t3=ch3.split(' ')
s,x1,x2=int(t1[0]),int(t1[1]),int(t1[2])
t1,t2=int(t2[0]),int(t2[1])
d,p=int(t3[0]),int(t3[1])
if t1>=t2:
    print (abs(x2-x1)*t2)
else:
    a=abs(x2-x1)*t2
    if (p==1) and (x2<x1):
        b=(2*s-d-x2)*t1
    elif (p==1) and (x1<x2):
        if d>x1 :
            b=(2*s-d+x2)*t1
        else:
            b=(x2-d)*t1
    elif (p==-1) and (x1<x2):
        b=(d+x2)*t1
    elif (p==-1) and (x2<x1):
        if d<x1 :
            b=(2*s+d-x2)*t1
        else:
            b=(d-x2)*t1
    print(min(a,b))