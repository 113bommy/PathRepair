n, k = map(int, input().split())
ans = []
if (n % (2 * k + 1) >= (k + 1) or n % (2 * k + 1) == 0):
    for i in range(n):
        if (i % (2 * k + 1) == k):
            ans.append(i)
else:
    ans.append(1)
    for i in range(k + 1, n):
        if (i % (2 * k + 1) == 1):
            ans.append(i)
print(len(ans))
for el in ans:
    print(el, end=' ')