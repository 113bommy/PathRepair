from sys import stdin
input = stdin.readline

t = int(input())
for _ in range(t):
    n, m = [int(x) for x in input().split()]
    p = [int(x) for x in input().split()]
    
    correct = [0]*(n+2)
    for i in range(n):
        if p[i] > i + 1:
            correct[n - (p[i] - (i + 1))] += 1
        else:
            correct[(i + 1) - p[i]] += 1
    
    correct_needed = n - 2 * m
    candidates = []
    for i in range(n):
        if correct[i] >= correct_needed:
            candidates.append(i)
    
    ans = []
    for k in candidates:
        switches_needed = 0
        visited = [False]*(n+2)
        for i in range(n):
            if visited[i]:
                continue
            component_size = 0
            node = i
            while visited[node] == False:
                visited[node] = True
                component_size += 1
                node = (p[i] - k) % n
            switches_needed += component_size - 1
        
        if switches_needed <= m:
            ans.append(k)
            
    print(str(len(ans)) + " ", end="")
    print(*ans)
                
            