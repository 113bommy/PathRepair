N = int(input())
a = list(map(int, input().split()))
res = 0
for i in range(N):
    res ^= a[i]
if res == 0:
    print('Yes')
else:
    print('No')