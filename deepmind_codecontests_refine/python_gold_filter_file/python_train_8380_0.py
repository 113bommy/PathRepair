q,b,c,d = map(int,input().split())
s = input()
x,y =c,d
l = 1
print(1,end = ' ')
a = set()
a.add((c,d))
for i in range(len(s)-1):
    item = s[i]
    if (item == 'U'):
        if(x == 1 or (x-1,y) in a):
            print(0,end = ' ')
            if(x-1,y) in a:
                x-=1
        else:
            print(1,end = ' ')
            x-=1
            l+=1
    elif item == 'R':
        if(y == b or (x,y+1) in a):
            print(0,end =' ')
            if(x,y+1) in a:
                y+=1
        else:
            print(1,end = ' ')
            y+=1
            l+=1
    elif item == 'L':
        if(y == 1 or (x,y-1) in a):
            print(0,end = ' ')
            if(x,y-1) in a:
                y-=1
        else:
            print(1,end = ' ')
            y-=1
            l+=1
    else:
        if(x == q or (x+1,y) in a):
            print(0,end = ' ')
            if(x+1,y) in a:
                x+=1
        else:
            print(1,end = ' ')
            x+=1
            l+=1
    a.add((x,y))
print(q*b-l)