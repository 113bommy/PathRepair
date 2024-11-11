t = int(input())
for _ in range(t):
    a = input()
    sum = 0
    s = set()
    x = 0
    y = 0
    for i in range(len(a)):
        x1 = x
        y1 = y
        if a[i]=='N':
            y+=1
        elif a[i]=='S':
            y-=1
        elif a[i]=='E':
            x+=1
        else:
            x-=1
        if (x,y,x1,y1) in s or (x1,y1,x,y) in s:
            sum+=1
        else:
            sum+=5
            s.add((x,y,x1,y1))
            s.add((x1,y1,x,y))
    print(sum)        
            
    
            
            
            
            