N,M = map(int,input().split())
A = [[] for i in range(N+1)]

for i in range(M) :
    l,r,d = map(int,input().split())
    
    l -= 1
    r -= 1
    
    A[l].append([r,d])
    A[r].append([l,d])

distance = ["#" for i in range(N)]

ans = "Yes"

flg = 0

for i in range(N) :
    if flg == 1 :
        break
    
    if distance[i] != "#" :
        continue
    
    distance[i] = 0
    stack = [i]
    
    while stack :
        v = stack.pop()
        
        for to,d in L[v] :
            if distance[to] == "#" :
                distance[to] = distance[v] + d :
                stack.append(to)
            
            elif distance[to] != distance[v] + d :
                ans = "No"
                stack = []
                flg = 1
                break
                

print(ans)