import math
num = 2 * (int(input()) - 1)
print(math.factorial(num) / (math.factorial(num / 2) ** 2))