for _ in range(int(input())):
    a,b,n = map(int,input().split())
    c = 0
    while(a<=n or b<=n):
        if a<b:
            a += b
            c+=1
        else:
            b += a
            c+=1
    print(c)