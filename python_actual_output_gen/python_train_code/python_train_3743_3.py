n,m,k = (int(x) for x in input().split())
h = set(int(x) for x in input().split()) 
cur_pos = 3
for _ in range(k):
    [u,v] =[int(x) for x in input().split()]
    if cur_pos in h:
        break
    if cur_pos == u:
        cur_pos = v
    elif cur_pos == v:
        cur_pos = u
print(cur_pos)