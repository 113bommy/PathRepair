for _ in " "*int(input()):
    d={};x,y=0,0;ans=0
    for i in input():
        x1,y1=x,y
        if i=='N':y1+=1
        elif i == 'S':y1-=1
        elif i == 'E':x1+=1
        else:x-=1
        if (x, y,x1,y1) in d or (x1,y1,x,y) in d:ans += 1
        else:ans += 5;d[(x, y,x1,y1)] = 1
    print(ans)
