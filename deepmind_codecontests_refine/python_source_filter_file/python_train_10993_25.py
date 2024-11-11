import math
n = int(input())
L = ['Sheldon','Leonard','Penny','Rajesh','Howard']
for i in range(30):
    if (2**(i+1))*5-5 > n:
        m = 2**i
        k = n-(2**i)*5+5
        p = math.ceil(k/m)-1
        for i in range(5):
            if i == p:
              print(L[i])
        break
