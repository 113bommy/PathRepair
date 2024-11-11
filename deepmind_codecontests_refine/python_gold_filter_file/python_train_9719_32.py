x = list(map(int, input().split()))

a = x[0] * x[1] / x[2]
a = a**0.5

b = x[1] * x[2] / x[0]
b = b**0.5

c = x[2] * x[0] / x[1]
c = c**0.5

print(int(4*(a+b+c)))