n = int(input())
a = int(n**0.5)

b, c = 1, n

for i in range(1, a):
    if n % i == 0:
        b = i
        c = n // i
print(str(b) + str(c))
