def check(x):
    global q
    if x == 2 or x == 4 or x==8:
        q+=1
        print(q)
        return q

    else:
        if x % 8 == 0:
            q+= 1
            check(x//8)
        elif x % 4 == 0:
            q+= 1
            check(x//4)
        elif x % 2 == 0:
            q+= 1
            check(x//2)
        else:
            return (-1)

for i in range(int(input())):
    q = 0
    
    a,b = map(int,input().split())
    
    if  a == b:
        print(0)
        
    elif b%a == 0:
        x = b//a
        check(x)
    
    elif a%b == 0:
        x = a//b
        check(x)
        
    else:
        print(-1)

