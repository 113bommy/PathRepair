import math
n = int(input())

count = 0


while n >= 2:
    x = math.floor(math.log(n,2))
    n = n - pow(2,x)
    count += 1

print(count + n)