from math import sqrt

n = int(input())
count = 1

for i in range(2,int(sqrt(n))):
    if n%i == 0:
        if n == i*i:
            count += 1
        else:
            count += 2

print(count)
