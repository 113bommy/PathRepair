import math
n = int(input())
m = int(input())
if math.log(m)<2*math.log(n):
    print(m)
else:
    print(m%2**n)