import math
 
n, m = map(int, input().split())
print((math.factorial(n+2*m-1)//(math.factorial(n-1) * math.factorial(2*m)))%10**9 + 7)