import math
n = int(input())
nn = int(math.sqrt(n))
while n%nn != 0: nn-=1
print(len(str(n/nn)))