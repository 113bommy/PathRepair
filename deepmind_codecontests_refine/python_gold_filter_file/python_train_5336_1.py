from math import sqrt
t = int(input())
for _ in range(t):
    n = int(input())
    rangeLoop = int(sqrt(n)) + 1
    smallDivisor = -1
    for i in range(2,rangeLoop):
        if n % i == 0:
            smallDivisor = i
            break
    if smallDivisor == -1:
        print("1 " + str(n-1))
    else: 
        print(str(n//smallDivisor) + ' ' + str(n-n//smallDivisor))