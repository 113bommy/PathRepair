t=int(input())
for i in range(t):
    n = int(input())
    sum = 0
    i = 0
    while True:
        a = pow(2, i)
        if a > n:
            break
        else:
            sum = sum + a
        i += 1

    print((n  * (1 + n))//2 - 2 * sum)