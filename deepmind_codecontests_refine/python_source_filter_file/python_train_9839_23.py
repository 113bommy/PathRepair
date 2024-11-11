n = int(input())
for test in range(n):
    num = int(input())
    res = int((1 + num)*num/2)
    deg = 0
    while 2**deg <= num:
        deg += 1
    res -= 2*(2**deg-1)
    print(res)
