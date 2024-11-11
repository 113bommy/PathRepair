n = int(input())
ind = 0
g = [set() for x  in range(101)]
arr = []
visited = set()
def dfs(src, dest):
    global visited
    visited.add(src)
    if dest in visited:
        return True
    ans = False
    for v in g[src]:
        if v not in visited:
            ans = ans or dfs(v, dest)
    return ans
        
    
for _ in range(n):
    type, x, y = map(int, input().split())
    visited = set()
    if type == 1:
        for j in range(len(arr)):
            if arr[j][0] < x < arr[j][1] or arr[j][0] < y < arr[j][1]:
                g[ind].add(j)
            if x < arr[j][0] < y or x < arr[j][1] < y:
                g[j].add(ind)
        arr.append([x, y])
        ind += 1
    elif dfs(x, y):
        print("YES")
    else:
        print("NO")
