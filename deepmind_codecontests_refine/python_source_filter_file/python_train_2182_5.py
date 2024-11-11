while True:
    n = int(input())
    if n == 0:
        break
    c = 0
    for i in range(2, 1001):
        for a in range(1, 1001):
            if i*a+(0.5*(i-1)*i) == n:
                c += 1
    print(c)

