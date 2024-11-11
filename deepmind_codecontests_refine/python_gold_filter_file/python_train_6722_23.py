import math

def displaysize(n):
    s = int(math.floor(math.sqrt(n)))  
    while n % s != 0:
        s -= 1
    return (s,n//s)

if __name__=="__main__":
    i = int(input())
    a,b = displaysize(i)
    print(str(a) + "   " + str(b))

