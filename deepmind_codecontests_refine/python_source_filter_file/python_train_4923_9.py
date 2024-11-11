# import os

t = int(input())

for _ in range(t):
    n, c0, c1, h = map(int, input().split())
    s = input()

    price_base = 0
    price = []
    for i in s:
        if i == '0':
            price_base += c0
        else:
            price_base += c1
    price.append(price_base)
    

    n_0 = s.count('0')
    n_1 = s.count('1')

    # changer les 0 en 1
    ss = s[:]
    for i in range(1, n_0):
        p = price_base + i*h - i*c0 + i*c1
        price.append(p) if p >= 0 else None
    ss = s[:]
    for i in range(1, n_1):
        p = price_base + i*h -i*c1 + i*c0
        price.append(p) if p >= 0 else None


    
    print(min([price]))


# 04/01 - 21
# 05/01 - 27
# 06/01 - 28





    