import math
Candies=int(input())

def reparto(n):
    m=(math.sqrt(n))
    print(int(m))
    for i in range(1,int(m)):
        n-=i
        print(i)
    return n

print(reparto(Candies))