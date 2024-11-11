import math
N, M = map(int, input().split())
if abs(M-N) > 2:
    print(0)
elif M == N:
    ans = math.factorial(M) * math.factorial(N) * 2 % (10**9+7)
    print(ans)
else:
    ans = math.factorial(M) * math.factorial(N) % (10**9+7)
    print(ans)
