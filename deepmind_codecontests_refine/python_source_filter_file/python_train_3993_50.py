import math

n,m,a=map(int,input().split())
print(math.ceil(n/m)+math.ceil(m/a))