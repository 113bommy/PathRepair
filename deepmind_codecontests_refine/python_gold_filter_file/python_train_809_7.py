N = int(input())
A = list(map(int, input().split()))
res = 0
for i in range(N):
    res ^= A[i]
if res == 0:
    print('Yes')
else:
    print('No')