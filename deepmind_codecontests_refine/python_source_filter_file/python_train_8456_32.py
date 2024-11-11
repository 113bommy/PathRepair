from math import pow as pow

q = int(input())

for i in range(q):
    n = int(input())
    k = 2
    while n % (pow(2, k) - 1) != 0:
        k += 1
    print(n / ((pow(2, k) - 1)))