n = int(input())
a = [0,0]+[int(input()) for _ in range(n-1)]
isleaf = [0,0]+[1 for _ in range(n)]
chleaf = [0,0]+[1 for _ in range(n)]
for i in range(2,n+1):
    isleaf[a[i]] = 0

for i in range(2,n+1):
    if isleaf[i]:
        chleaf[a[i]] += 1

ans = "Yes"
for i in range(1, n+1):
    if not isleaf[i] and chleaf[i] < 3:
        ans = "No"
        break
print(ans)
