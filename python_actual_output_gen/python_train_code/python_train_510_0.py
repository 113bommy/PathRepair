N = int(input())
K = [0 for i in range(N+1)]
A = list(map(int,input().rstrip().split(" ")))
ans = 1
for i in A:
    K[i] += 1
for i in range(N):
    if i != 0 and K[i] != 0 and K[i] != 2:
        ans = -1
        break
    if K[i] == 2:
        ans *= 2
        ans %= 10 ** 9 + 7
print(ans)