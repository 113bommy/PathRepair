H, W, h, w = [ int(v) for v in input().split() ]
if H % h == 0 and W% w == 0:
    print("No")
else:
    print("Yes")
    grid = [ [ -h*w*100000+99999 if i % h == h-1 and j % w == w-1 else 100000 for j in range(W) ] for i in range(H) ]
    for i in grid:
        print(*i)
