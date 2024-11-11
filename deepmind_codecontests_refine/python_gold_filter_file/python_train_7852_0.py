n, x = map(int, input().split())
can = [[], []]
for i in range(n):
    a, b, c = map(int, input().split())
    can[a].append((b, c))
ans = 0
for nturn in range(2):
    u = [[], []]
    for i in range(2):
        for j in range(len(can[i])):
            u[i].append(False)
    nx = x
    nw = 0
    turn = nturn
    for i in range(n):
        mx = -1
        bj = -1
        for j in range(len(can[turn])):
            if not u[turn][j] and can[turn][j][0] <= nx and can[turn][j][1] > mx:
                bj = j
                mx = can[turn][j][1]
        if bj != -1:
            nx += mx
            u[turn][bj] = True
            nw += 1
        else:
            break
        turn = (turn + 1) % 2
    ans = max(ans, nw)
print(ans)
    
        
        
            
        
        
    
    

pass
