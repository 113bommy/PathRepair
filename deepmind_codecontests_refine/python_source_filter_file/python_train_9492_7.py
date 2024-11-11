import math

size = int(input())
array = [int(el) for el in input().split()]

def gcd(a, b):
    return a if (b == 0) else gcd(b, a % b)

def getArrayGCD(array):
    if (len(array) == 1):
        return array[0]

    arrayGcd = gcd(array[0], array[1])
    for i in range(2, len(array) - 1):
        arrayGcd = gcd(arrayGcd, array[i])
    
    return arrayGcd

arrayGcd = getArrayGCD(array)

if (arrayGcd == 1):
    print(1)
else:
    devidersCount = 0
    for i in range(1, int(math.sqrt(arrayGcd)) + 1):
        if (i*i == arrayGcd):
            devidersCount += 1
        elif (arrayGcd % i == 0): 
            devidersCount += 2

    print(devidersCount)