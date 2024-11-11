N = int(input())
a = list(map(int,input().split()))
cc = []
res = a[0]
for i in range(1,N):
    res ^= a[i]
if res == 0:
    print('Yes')
else:
    print('No')