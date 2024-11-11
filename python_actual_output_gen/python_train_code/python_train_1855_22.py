n,m = map(int, input().split())
h = []
for i in range(m):
    h.append(0)
for i in range(n):
    x = int(input())
    if h[x%m]==1:
        print(i+1)
        exit()
    else:
        h[x%m] = 1
print(-1)