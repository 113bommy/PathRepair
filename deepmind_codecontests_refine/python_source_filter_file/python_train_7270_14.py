import math 
def lcm(a, b):
    return a * b / math.gcd(a, b)

n = int(input())

ans = 1
for i in range(n):
    ans = lcm(ans, int(input()))

print(ans)