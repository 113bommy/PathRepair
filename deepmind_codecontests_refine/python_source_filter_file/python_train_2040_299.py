import math
n=int(input())
 
answer=(math.ceil(n//2)+n)%(n+1)

print(answer)