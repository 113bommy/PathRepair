n, m = map(int, input().split())
h = list(map(int, input().split()))
ans = [1] * n
for i in range(m):
    ai, bi = map(int, input().split()) 
    if h[ai-1] >= h[bi-1]:
        ans[bi-1] = 0
    elif h[ai-1] < h[bi-1]:
        ans[ai-1] = 0
print(sum(ans))