import math
n = int(input())
C = math.factorial(n) / ((math.factorial(n/2)) * (math.factorial(n/2))) * math.factorial(n/2-1) * math.factorial(n/2-1) / 2
print(C)