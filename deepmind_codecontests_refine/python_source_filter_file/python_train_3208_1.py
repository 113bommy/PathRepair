n = int(input())

ans = []
if n & 1 == 1:
    for i in range(n):
        if i + 1 != n:
            ans.append((i+1, n))
    n -= 1

for i in range(n):
    for j in range(1, n+1):
        if j != n - i and j != i + 1:
            ans.append((i+1, n))

print(len(ans))
for i in range(len(ans)):
    print(ans[i][0], ans[i][1])