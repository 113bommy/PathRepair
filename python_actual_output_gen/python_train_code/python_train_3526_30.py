n = int(input())
n += n % 2
n //= 2
if n % 2 != 0:
    n *= -1
print(n)
