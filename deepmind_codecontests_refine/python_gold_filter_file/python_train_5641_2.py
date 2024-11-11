n = int(input())

while n:
    n -= 1

    b, p, f = map(int, input().split())
    h, c = map(int, input().split())

    price = 0
    
    if h > c and b >= 2:
        price += min(p, b//2) * h

        b -= price // h * 2 

        if b > 1:
            price += min(f, b//2) * c

    elif b >= 2:
        price += min(f, b//2) * c

        b -= price // c * 2 

        if b > 1:
            price += min(p, b//2) * h

    print(price)
