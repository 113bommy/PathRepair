N = int(input())
import math

x = math.ceil(N / 1.08)
print(str(x) if math.floor(x * 1.8) == N else ':(')