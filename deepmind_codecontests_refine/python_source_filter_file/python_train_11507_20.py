import math
n = int(input())
print(int(math.factorial(n)/(math.factorial(5)*math.factorial(n-5))+math.factorial(n)/(math.factorial(6)*math.factorial(n-6))+math.factorial(n)/(math.factorial(7)*math.factorial(n-7))));