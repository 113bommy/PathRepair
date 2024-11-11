import math
Candies=int(input())

def reparto(n):
    m=(math.sqrt(8*n+1)-1)/2
    print(int(m))
    for i in range(1,int(m)):
        n-=i
        print(i)
    return n

print(reparto(Candies))