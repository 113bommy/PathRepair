import math
n=int(input())
if int(n**0.5)==n**0.5:
    exit(print(2*int(n**0.5)))
a=int(n**0.5)+1
print(a+math.ceil(n/a))