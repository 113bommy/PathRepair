min_r1 = 1000000001
max_l1 = 0
max_l2 = 0
min_r2 = 1000000001

n = int(input())
for i in range(n):
    l1, r1 = map(int, input().split())
    min_r1 = min(min_r1, r1)
    max_l1 = max(max_l1, l1)
m = int(input())
for i in range(m):
    l2, r2 = map(int, input().split())
    min_r2 = min(min_r2, r2)
    max_l2 = max(max_l2, l2)

ans = 0
if min_r1 < max_l2:
    ans = max_l2 - min_r1
if min_r2 < max_l1:
    ans = max(ans, max_l1, min_r2)
print(ans)
