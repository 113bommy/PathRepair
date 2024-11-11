
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))



t=inp()


for i in range (t):
    
    w,h=invr()

    x1=inlt()
    x2=inlt()
    y1=inlt()
    y2=inlt()
    
    l=[]
    gx1=x1[1]-x1[-1]
    l.append(gx1*h)

    gx2=x2[1]-x2[-1]
    l.append(gx2*h)

    gy1=y1[1]-y1[-1]
    l.append(gy1*w)

    gy2=y2[1]-y2[-1]
    l.append(gy2*w)

    print(max(l))



    

    

























