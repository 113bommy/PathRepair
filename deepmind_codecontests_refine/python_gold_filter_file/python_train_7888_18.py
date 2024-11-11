N = int(input())
arm = []
for n in range(N):
    i, L = map(int, input().split())
    arm.append([i+L, i-L])
sarm = sorted(arm)
pre = -10**10
count = 0
for a in sarm:
    if pre <= a[1]:
        count += 1
        pre = a[0]
print(count)