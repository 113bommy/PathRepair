n, a, b, c = [int(input()) for _ in range(4)]

# n=ax+

use = max(0, (n - b) // (b - c))
rem = n - use * (b - c)
x = rem // b
ans = max(n // a, use + max(rem // a, x + (rem - x * b + c * x) // a))
print(ans)

