a = int(input())
k = 1

if a == 1 or a == 2:
    print(-1)
else:
    if a % 2 != 0:
        b = a * a // 2
        c = b + 1
    else:
        k *= 2
        a //= 2 
        if a % 2 != 0:
            b = k * (a ** 2 // 2)
            c = k * (a ** 2 // 2 + 1) 
        else:
            b = 3 * (a // 2)
            c = 5 * (a // 2)


    print(b, c)