n=int(input())
a=int(input())
b=int(input())
c=int(input())

if a<=b-c:
    print(n//a)
else:
    if n < b:
        print(n // a)
    else:
        v = (n-b) // (b-c) * (b-c)
        kol = (n-b) // (b-c)

        d = n - v

        while d >= b:
            d -= b
            d += c
            kol += 1
            
        kol += d//a

        print(kol)
