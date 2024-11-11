def formvalid(x1,y1,x2,y2):
    if(y2>=y1 and x2>=x1):
        return 1
    else:
        return 0
def numofblack(n,m,xi,yi):
    total=n*m
    if(total%2==1 and abs(yi-xi)%2==1):
        return total//2+1
    elif(total%2==1 and abs(yi-xi)%2==0):
        return total//2-1
    else:
        return total//2
def numofwhite(x1,y1,x2,y2):
    n=y2-y1+1
    m=x2-x1+1
    return n*m-numofblack(n,m,x1,y1)
t=int(input())
for you in range(t):
    l=input().split()
    n=int(l[0])
    m=int(l[1])
    numofb=numofblack(n,m,1,1)
    numofw=n*m-numofb
    #print(numofb,numofw)
    x=input().split()
    x1=int(x[0])
    y1=int(x[1])
    x2=int(x[2])
    y2=int(x[3])
    numofb-=numofblack((y2-y1+1),(x2-x1+1),x1,y1)
    numofw=n*m-numofb
    #print(numofb,numofw)
    x=input().split()
    xx1=int(x[0])
    yy1=int(x[1])
    xx2=int(x[2])
    yy2=int(x[3])
    xfi1=max(xx1,x1)
    yfi1=max(yy1,y1)
    xfi2=min(xx2,x2)
    yfi2=min(yy2,y2)
    if(formvalid(xfi1,yfi1,xfi2,yfi2)==0):
        numofw-=numofwhite(xx1,yy1,xx2,yy2)
        numofb=n*m-numofw
    else:
        numofw=numofw-numofwhite(xx1,yy1,xx2,yy2)+numofwhite(xfi1,yfi1,xfi2,yfi2)-((yfi2-yfi1+1)*(xfi2-xfi1+1))
        numofb=n*m-numofw
    print(numofw,numofb)
