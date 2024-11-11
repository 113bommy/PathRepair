n = int(input())
list1 = list(map(int, input().split()))
mx = 0
for i in range(n-1):
    t = 1
    total = list1[i]
    if total > 100:
        mx = max(1, mx)
    for j in range(i + 1, n):
        t += 1
        total += list1[j]
        if total > t * 100:
            mx = max(t, mx)
print(mx)