for t in range(int(input())):
    a, b, c = map(int, input().split())
    cnt = 0
    if(a > 0):
        a -= 1
        cnt += 1
        
    if(b > 0):
        b -= 1
        cnt += 1
        
    if(c > 0):
        c -= 1
        cnt += 1
        
    if(a >= b and a >= c):
        
        if(a > 0 and b > 0):
            a -= 1
            b -= 1
            cnt += 1
        if(b > 0 and c > 0):
            b -= 1
            c -= 1  
            cnt += 1
        if(a > 0 and c > 0):
            a -= 1
            c -= 1
            cnt += 1
    if(b >= a and b >= c):
        if(a > 0 and b > 0):
            a -= 1
            b -= 1
            cnt += 1
        if(b > 0 and c > 0):
            b -= 1
            c -= 1  
            cnt += 1
        if(b > 0 and a > 0):
            b -= 1
            a -= 1
            cnt += 1
    elif(c > a and c > a):
        if(c > 0 and a > 0):
            c -= 1
            a -= 1
            cnt += 1
        if(c > 0 and b > 0):
            c -= 1
            b -= 1
            cnt += 1
        if(b > 0 and a > 0):
            b -= 1
            a -= 1
            cnt += 1
    elif(a > 0 and  b > 0 and c > 0):
        cnt += 1
    print(cnt)
