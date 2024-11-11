n = int(input())

if n == 1:
    print(1)

else:
    import math
    if n > 1000:
        k = math.sqrt(n)
        k = math.ceil(k) 
    else:
        k = n + 1
    p = n
    for i in range(2,k+1):
        if p % i == 0:
            while p % i == 0:
                p = p / i
            break

    if p == 1:
        print(i)

    elif p == n:
        print(n)
        
    else:
        print(1)