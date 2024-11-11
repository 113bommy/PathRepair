# D
H, W, N = map(int,input().split())
field_dict = dict()
X_list = [0]*N
Y_list = [0]*N

for i in range(N):
    X, Y = map(int,input().split())
    X_list[i] = X-1
    Y_list[i] = Y-1
    field_dict[(X-1)*1000000 + (Y-1)] = 1

def query(posi_x, posi_y):
    return field_dict.get(posi_x*1000000+posi_y, 0)

# minimam x reachable
reach_y = [W]*H
reach_y[0] = 0
posi_x, posi_y = 0, 0

while posi_x < W - 1:
    # takahashi
    if query(posi_x+1, posi_y) == 1:
        # gameover
        break
    else:
        posi_x += 1
    # aoki
    if query(posi_x, posi_y+1) == 0 and posi_y + 1 < H:
        # move
        posi_y += 1
        reach_y[posi_y] = posi_x
        
res = W

for i in range(N):
    if reach_y[Y_list[i]] < X_list[i]:
        res = min(res, X_list[i])
        
print(res)