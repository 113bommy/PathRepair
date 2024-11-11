def path(string):
    blanck=set()
    x=0
    y=0
    t=0
    px,py=0,0
    for i in string:
        if i=="N":
            y+=1
            if (px,py,x,y) not  in blanck :
                t+=5
            else:
                t+=1
        if i=="S":
            y-=1
            if (px,py,x,y) not  in blanck:
                t+=5
            else:
                t+=1
        if i=="E":
            x+=1
            if (px,py,x,y) not  in blanck:
                t+=5
            else:
                t+=1
        if i=="W":
            x-=1
            if (px,py,x,y) not  in blanck :
                t+=5
            else:
                t+=1
        blanck.add((px,py,x,y))
        blanck.add((x,y,px,py))
        px,py=x,y

    return t,blanck

n=int(input())
for i in range(n):
    print(path(input()))