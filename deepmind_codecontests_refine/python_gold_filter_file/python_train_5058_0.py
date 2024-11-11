n = int(input())
arr = [(0, 0) for _ in range(n)]
ml1 = ml2 = -(10**9)
mr1 = mr2 = (10**9)
for i in range(n):
    l, r = map(int, input().split())
    ml1 = max(ml1, l)
    mr1 = min(mr1, r)
m = int(input())
for i in range(m):
    l, r = map(int, input().split())
    ml2 = max(ml2, l)
    mr2 = min(mr2, r)
ans = ml2 - mr1
ans1 = ml1 - mr2
#print(ans, ans1)
print(max(ans, ans1, 0))
