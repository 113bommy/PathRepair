#168A
import math
n, x, y = map(int, input().split())
print(math.ceil((n*y)/100) - x)
