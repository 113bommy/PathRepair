H, W = list(map(int, input().split()))
M = [[-1]*(W+2)]
ans = 0
for _ in range(H):
    s = input()
    ans += s.count('.')
    M.append([-1]+[0 if c=='.' else -1 for c in s]+[-1])
M += [[-1]*(W+2)]

queue = [(1,1)]
M[1][1] = 1
dr = [(+1,0),(-1,0),(0,+1),(0,-1)]
turn = 1
while len(queue)>0:
    turn += 1
    queue_new = []
    for qx, qy in queue:
        for dx, dy in dr:
            x, y = qx+dx, qy+dy
            if M[y][x]==0:
                M[y][x] = turn
                queue_new.append((x,y))
    queue = queue_new

print(ans-M[H][W] if M[H][W]>-1 else -1)