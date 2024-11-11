from math import sqrt
N = int(input())

ans = 0
for i in range(1, int(sqrt(N))+1):
    print(i)
    if N%i == 0 and i < N//i-1:
        ans += N//i-1

print(ans)