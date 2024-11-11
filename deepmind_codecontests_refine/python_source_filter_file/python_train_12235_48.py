import math

n = int(input())

summ = 0

summ += int(3 ** (2 * n - 2 - n - 1)) * 3 * 4 * 2
summ += int(3 ** (2 * n - 2 - n - 2)) * 3 * 3 * 4 * (2 * n - 2 - n - 1)
    
print(summ)