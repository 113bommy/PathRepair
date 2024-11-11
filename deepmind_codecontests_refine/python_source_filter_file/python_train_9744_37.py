import math

n,k=[int(i) for i in input().split()]
m=sum([int(i) for i in input().split()])
print(math.ceil(2*(n*(k-0.5)-m)))