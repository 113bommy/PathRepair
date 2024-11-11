t,sx,sy,ex,ey = map(int,input().split())
direct = input()
x=y=0
rx = ex-sx
ry = ey-sy
check = 0
for i in range(t):
    if rx>=0 and ry>=0:
        if direct[i]=='N':
            if y<ry:
                y += 1
        elif direct[i]=='E':
            if x<rx:
                x += 1
        if x==rx and y==ry:
            check = 1
            index = i
            break
    elif rx>=0 and ry<0:
        if direct[i]=='S':
            if y<-ry:
                y += 1
        elif direct[i]=='E':
            if x<rx:
                x += 1
        if x==rx and y==-ry:
            check = 1
            index = i
            break
    elif rx<0 and ry>=0:
        if direct[i]=='N':
            if y<ry:
                y += 1
        elif direct[i]=='W':
            if x<-rx:
                x += 1
        if x==-rx and y==ry:
            check = 1
            index = i
            break
    else:
        if direct[i]=='S':
            if y<-ry:
                y += 1
        elif direct[i]=='W':
            if x<-rx:
                x += 1
        if x==-rx and y==-ry:
            check = 1
            index = i
            break
if check:
    print(index+1)
else:
    print(-1)

