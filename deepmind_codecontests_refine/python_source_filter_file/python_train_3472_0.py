import math

R1 = input().split(" ")
P1 = input().split(" ")
P2 = input().split(" ")
ab = input().split(" ")

a = float(ab[0])
b = float(ab[1])

def maximum(lst):
    max = -1
    for el in lst:
        if float(el) > max:
            max = float(el)
    return max
    
def minimum(lst):
    min = float('inf')
    for el in lst:
        if float(el) < min:
            min = float(el)
    return min

r1 = maximum( R1[1:] )
p2 = minimum( P2[1:])

r2 = 0
max = -1
for p1i in P1:
    nominator = b * float(p1i) * r1**2
    denominator = a*p2 + b* float(p1i)
    r2 = math.sqrt(nominator / denominator)
    
    if(r2 > max):
        max = r2

print(r2)
    