n, q = map(int, input().split())
arr = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    arr[a-1].append(b)
    
ans = [0 for _ in range(n)] 

for _ in range(q):
    p, x = map(int, input().split())
    ans[p-1] += x
    
for i, c in enumerate(ans):
    for j in arr[i]:
        ans[j-1] += c
            
print(ans)

