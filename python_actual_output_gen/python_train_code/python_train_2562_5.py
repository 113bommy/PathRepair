for _ in range(int(input())):
    n = int(input())
    a,b,c = 6,10,14
    if n<30:
        print("NO")
    else:
        print("YES")
        z = n - (a+b+c)
        if z==a or z==b or z==c:
            c = 15
        print(a,b,c,n-(a+b+c))