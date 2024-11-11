import math
A1,A2,A3 = map(int,input().split())
b = math.sqrt(A1*A2*A3)
print(int(4*(b/A1 + b/A2 + b/A3)))