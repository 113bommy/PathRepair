import math
n = int(input())
x = math.sqrt(1+24*n)/6
print(int((x+n%3)//3) )