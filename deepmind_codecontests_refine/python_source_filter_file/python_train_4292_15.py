import math

def GetNumber(start, n, number, count):
    if count == 1 and n > start:
        number += (str(n))
        print("YES")
        print(number)
        return 
    for i in range(start, int(math.sqrt(n)) + 1):
        if n % i == 0:
            number += (str(i)+" ")
            count -= 1
            GetNumber(i+1, int(n / i), number, count)
            return
    print("No")
    return



inputCount = int(input(""))

for i in range(0, inputCount):
    n = int(input(""))
    GetNumber(2, n, "", 3)