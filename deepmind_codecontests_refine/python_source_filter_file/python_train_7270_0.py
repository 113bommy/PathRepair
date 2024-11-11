import math
n = int(input())
t = [int(input()) for i in range(n)]
ans = 1
for i in t:
    ans = ans * i // math.gcd(ans,i)
print(ans)