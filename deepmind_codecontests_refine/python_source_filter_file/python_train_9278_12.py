import math
n = eval(input())
z = math.ceil(math.sqrt(n))
x = n // z
if (x+z)< n :
    x+=1
print(x+z)