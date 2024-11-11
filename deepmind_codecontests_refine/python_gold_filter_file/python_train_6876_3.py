dice = {v: k for k, v in enumerate(list(map(int, input().split())))}
adjacent = {k: v for k, v in enumerate(sorted(dice.keys()))}
q = int(input())
p = [(-1,2,4,1,3,-1),(3,-1,0,5,-1,2),(1,5,-1,-1,0,4),(4,0,-1,-1,5,1),(2,-1,5,0,-1,3),(-1,3,1,4,2,-1)]
for _ in range(q):
    top, front = map(int, input().split())
    x = dice[top]
    y = dice[front]
    print(adjacent[p[x][y]])