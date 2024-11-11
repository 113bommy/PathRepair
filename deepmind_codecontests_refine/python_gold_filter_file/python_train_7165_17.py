n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cnt = sum(b) - sum(a)
ans = 0
for ai, bi in zip(a, b):
    ans += max(0, (bi - ai + 1) // 2)
print('Yes' if ans <= cnt else 'No')
