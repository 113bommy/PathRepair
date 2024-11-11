import math
a = int(input())
for i in range(a):
 [n, x, a, b] = map(int,input().split())
 print(int(min(math.fabs(a-b)+x,n-1)))