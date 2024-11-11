import math

n, m = [int(x) for x in input().split()]

num_digits = math.ceil((n - 5) / 4) + 1

a = '5' * num_digits
b = ('4' * (num_digits-1)) + '5'

print(a)
print(b)
