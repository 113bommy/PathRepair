
import math
q = int(input())

for i in range(q):
    a , b = input().split(" ")
    a = int(a)
    b = int(b)

    if math.gcd(a,b) == 1:
        print("Finite")
    else:
        print("Infinte")
