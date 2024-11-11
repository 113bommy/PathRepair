import math

m, k = map(int, input().split())
print(int((math.sqrt(8*(k+m)+9)-3)//2)-1)