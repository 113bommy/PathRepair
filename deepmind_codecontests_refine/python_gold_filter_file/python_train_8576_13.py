a = int(input())

if a >=0:
    print(a)
else:
    # a = n * (-1)
    # last = a % 10
    # se_end = (a % 100) // 10
    # end = (a // 10 - se_end) + a % 10
    n=a*-1
    if n//10 >= (n//100*10)+n % 10:

        print(-1*((n//100*10)+n % 10))
    else:

        print((n // 10)*-1)

