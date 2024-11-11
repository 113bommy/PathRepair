n = int(input())
a = list(map(int, input().split()))

pos = [[] for i in range(n+1)]
for i in range(n*2):
    pos[a[i]].append(i+1)
ans = 0
print(pos)
for m in range(2):
    ans += abs(pos[1][m] - 1)
    for i in range(1,n):
        ans += abs(pos[i+1][m] - pos[i][m])
print(ans)
