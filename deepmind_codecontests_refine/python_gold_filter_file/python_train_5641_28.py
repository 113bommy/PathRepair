n = int(input())
for _ in range(n):
    b,p,f = map(int,input().split())
    h,c = map(int,input().split())
    if b<2:
        print("0")
    elif (p+f)*2 < b:
        print(p*h+f*c)
    else:
        if max(h,c)==c:
            if 2*f<b:
                print(f*c+(b-2*f)//2*h)
            else:
                print((b//2)*c)
        else:
            if 2*p<b:
                print(p*h+(b-2*p)//2*c)
            else:
                print((b//2)*h)