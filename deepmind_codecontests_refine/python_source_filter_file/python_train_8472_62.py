import math
length , term = [int(x) for x in input().strip().split()]
x = 0
if(term < int(length/2)):
    print((2*term) - 1)
else:
    x = math.ceil(length/2)
    x = term - x
    print(2*x)