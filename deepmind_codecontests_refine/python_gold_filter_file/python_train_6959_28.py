import math
n = int(input())
a = int(math.sqrt(n))
while n%a != 0: a-=1
print(len(str(n//a)))