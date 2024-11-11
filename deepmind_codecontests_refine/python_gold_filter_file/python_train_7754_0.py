n = int(input())
visited = [False] * n
k = 0
for i in range(n ** 2 + 1):
    k += i + 1
    visited[k % n] = True
for i in visited:
    if not i:
        print("NO")
        exit()
print("YES")
