import math
A, B = map(int,input().split())
ans = (A * B) // math.gcd(A, B)
print(ans)