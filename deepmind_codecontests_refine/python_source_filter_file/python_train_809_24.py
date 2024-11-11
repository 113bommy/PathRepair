N = int(input())
a = list(map(int, input().split()))
s = 0
for i in range(N):
    s ^= a[i]
print('Yes' if s == 0 else 'No')
