import math
N = int(input())
ans = 0
for i in range(1,int(math.sqrt(N+1))):
    if N % i == 0:
        ans += N//i - 1
print(ans)