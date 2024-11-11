R,x1,y1,x2,y2=map(int,input().split(' '))
d1=(x2-x1)**2+(y2-y1)**2
if d1>=R*R:
    print(str(x1)+" "+str(y1)+" "+str(R))
else:
    d2=R+d1**(0.5)
    if x1==x2 and y1==y2:
        print(str(x1+R/2)+" "+str(y1)+" "+str(d2/2))
    elif x1==x2:
        if y2>y1:
            print(str(x1)+" "+str((y1+y2-R)/2)+" "+str(d2/2))
        else:
            print(str(x1)+" "+str((y1+y2+R)/2)+" "+str(d2/2))
    elif y1==y2:
        if x2>x1:
            print(str((x1+x2-R)/2)+" "+str(y1)+" "+str(d2/2))
        else:
            print(str((x1+x2+R)/2)+" "+str(y1)+" "+str(d2/2)) 
    else:
        x2-=x1
        y2-=y1
        slp=y2/x2
        a=(R*R/(slp*slp+1))**(0.5)
        b=slp*a
        if x2<0 and y2<0:
            print(str((a+x2)/2+x1)+" "+str((b+y2)/2+y1)+" "+str(d2/2))
        elif x2<0 and y2>0:
            print(str((a+x2)/2+x1)+" "+str((y2-b)/2+y1)+" "+str(d2/2))
        elif x2>0 and y2<0:
            print(str((x2-a)/2+x1)+" "+str((y2+b)/2+y1)+" "+str(d2/2))
        else:
            print(str((x2-a)/2+x1)+" "+str((y2-b)/2+y1)+" "+str(d2/2))


        
        