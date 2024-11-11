for _ in " "*int(input()):
    d={};x,y=0,0;ans=0
    for i in input():
        x1,y1=x,y
        if i=='N':y+=1
        elif i == 'S':y-=1
        elif i == 'E':x+=1
        else:x-=1
        if (x, y,x1,y1) in d or (x1,y1,x,y) in d:ans += 1
        else:ans += 5;d[(x1, y1,x,y)] = 1
    print(ans)
