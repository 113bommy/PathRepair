import math
n,h = map(int, input().split())

for i in range(1,n+1):
    print(h * math.sqrt(i/n))