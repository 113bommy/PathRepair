N = int(input())
F = [int(input().replace(' ', ''), 2) for i in range(N)]
P = [[int(j) for j in input().split()] for j in range(N)]

ans = -float('inf')

for i in range(1, 2**10):
    temp = 0
    for j in range(N):
        temp += P[j][bin(i&F[j]).count('1')]
        ans = max(ans, temp)

print(ans)