from math import sqrt
n = int(input())
divisors = []

while n % 10 == 0 and int(n / 10) > 10:
    n = int(n / 10)

for i in range(2, round(sqrt(n)) + 1):
    if n % i == 0:
        divisors.append(i)
        divisors.append(n / i)

divisors.sort()

if len(divisors) == 0:
    print(n)
else:
    gcd = 1
    for i in range(2, min(divisors) + 1):
        for j in divisors:
            if j % i != 0:
                break
            if j == max(divisors):
                gcd = i
    print(gcd)

