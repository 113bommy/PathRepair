n, k, x = map(int, input().split())
levels = sorted(list(map(int, input().split())))
diffs = []
for i in range(n-1):
    diff = levels[i + 1] - levels[i]
    if diff <= x:
        continue
    else:
        diffs.append(diff // x)
diffs.sort()
counter = 0
if len(diffs) == 0:
    print(1)
else:
    for j in range(len(diffs)):
        if k - diffs[j] < 0:
            break
        k -= diffs[j]
        counter += 1
print(len(diffs) + 1 - counter)
