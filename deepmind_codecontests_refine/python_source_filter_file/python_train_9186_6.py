n = int(input())
l = list(map(int, input().split()))
ans = max(l)
for i in range(n):
    for j in range(i + 1, n):
        ans = max(ans, l[i] ^ l[j])
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            ans = max(ans, l[i] ^ l[j] ^ l[k])
print(ans)