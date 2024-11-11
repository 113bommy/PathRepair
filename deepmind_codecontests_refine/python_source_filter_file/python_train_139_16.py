n = int(input())
h = []
g = []
ans = 0
for u in range(n):
    H,A = map(int,input().split())
    h.append(H)
    g.append(A)
for j in range(n):
    for k in range(n):
        if j == k:
            break
        elif h[j] == g[k]:
            ans+=1
print(ans)