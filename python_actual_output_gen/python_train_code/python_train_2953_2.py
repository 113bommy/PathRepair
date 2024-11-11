def removeLastDigit(n):
    return n//10

def removeSecondLastDigit(n):
    i = n % 10
    return n//100 * 10 + i

n = int(input())
if(n >= 0):
    print(n)
else:
    x = removeLastDigit(n)
    y = removeSecondLastDigit(n)
    if(x > y):
        print(x)
    else:
        print(y)