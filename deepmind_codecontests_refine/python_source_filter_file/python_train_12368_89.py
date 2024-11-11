W,H,X,Y = map(int,input().split())
print(W * H / 2, 0 if W // 2 != X or H // 2 != Y else 1)