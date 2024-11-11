


a,b = map(int,input().split())



while True:
    if a==0 or b==0:
        break
    elif a>= 2*b:
        h = a//(2*b)
        a-=h*(2*b)
    elif b >= 2*a:
        v = b/(2*a)
        b -= v*(2*a)
    else:
        break


print(a,b)
        
