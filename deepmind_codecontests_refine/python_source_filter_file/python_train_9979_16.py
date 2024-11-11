import math
N = int(input())
d = math.factorial(N)

k, ans = 1, 1
for i in range(1, N + 1):
    while d % i == 0:
        d //= i
        k += 1
    ans *= k
    k = 1
print(ans % (10**9 + 7))
