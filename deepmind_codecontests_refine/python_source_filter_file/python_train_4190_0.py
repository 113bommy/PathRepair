from sys import stdin, stdout

tree = []
parent = []
go_in = []
go_out = []
d = []

def main():
    global tree
    global parent
    global go_in
    global go_out
    global d
    n,k = list(map(int, stdin.readline().split()))
    tree = [[] for _ in range(n+1)]
    parent = [0] * (n+1)
    go_in = [0] * (n+1)
    go_out = [0] * (n+1)
    d = [0] * (n+1)
    for _ in range (n-1):
        a,b = list(map(int, stdin.readline().split()))
        tree[a].append(b)
        tree[b].append(a)
    stack = []
    stack.append(1)
    parent[1] = 1
    d[1] = 1
    while stack:
        x = stack.pop()
        for y in tree[x]:
            if parent[y] == 0:
                parent[y] = x
                d[y] = d[x] + 1
                stack.append(y)
    stack = []
    stack.append(1)
    kk = 1
    while stack:
        
        x = stack[-1]
        if go_in[x] == 0:
            go_in[x] = kk
            kk += 1
        is_another = False
        while tree[x]:
            y = tree[x].pop()
            if go_in[y] == 0:
                stack.append(y)
                is_another = True
                break
        if is_another:
            continue
        go_out[x] = kk
        kk += 1
        stack.pop()
    for _ in range (k):
        branch = 1
        mx = -1
        arr = list(map(int, stdin.readline().split()))
        is_ok = True
        for i in range(len(arr)):
            if d[arr[i]] > mx:
                mx = d[arr[i]]
                branch = parent[arr[i]]
        for i in range(len(arr)):
            cur = parent[arr[i]]
            if (go_in[branch] <= go_in[cur] and go_out[branch] >= go_out[cur]) or (go_in[branch] >= go_in[cur] and go_out[branch] <= go_out[cur]):
                continue
                
            is_ok = False
            stdout.write("NO\n")
            break
        if is_ok:
            stdout.write("YES\n")
        
        
main()