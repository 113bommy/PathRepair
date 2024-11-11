import math
def theatre_square(n,m,a):
    return math.ceil(n / a) + math.ceil(m/a)
n,m,a = [int(i) for i in input().split()]
print(theatre_square(n,m,a))