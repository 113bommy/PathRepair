n, m = map(int, input().split())
a1 = [int(x) for x in input().split()]
a2 = [int(x) for x in input().split()]
a1.sort()
a2.sort()

ans1 = -1e18
ans2 = -1e18

for i in range(len(a1) - 1):
    for j in a2:
        ans1 = max(ans1, a1[i] * j)

for i in range(1, len(a1)):
    for j in a2:
        ans2 = max(ans2, a1[i] * j)

print(min(ans1, ans2))
