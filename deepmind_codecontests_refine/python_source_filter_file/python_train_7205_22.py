for i in range(int(input())):
    a,b,c,n = map(int,input().split())
    
    if (a+b+c+n) % 3 == 0:
        s = (a+b+c+n) / 3
        if (s > max(a,b,c)):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")