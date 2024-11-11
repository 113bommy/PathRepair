import math
a = int(input())
b = int(input())
c = int(input())
print(int(max(a+b+c, a*b*c, (a+b)*c, a*(a+b))))