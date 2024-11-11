n =int(input())
import fractions
ans = 1
for _ in range(n):
    t = int(input())
    ans = ans * t // fractions.gcd(ans, t)
print(ans)