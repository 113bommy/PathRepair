n =int(input())
import fraction
ans = 1
for _ in range(n):
    t = int(input())
    ans = ans * t // fraction.gcd(ans, t)
print(ans)