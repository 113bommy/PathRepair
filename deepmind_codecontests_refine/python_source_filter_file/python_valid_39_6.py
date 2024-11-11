def solve(W,x1,x2,w):
    if w + (x2-x1) < W:
        return 10000000000
    return min(max(0,w-x1),max(0,w-W+x2))

for _ in range(int(input())):
    W,H = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    w,h = map(int,input().split())

    answer = min(solve(W,x1,x2,w),solve(H,y1,y2,h))
    print(-1 if answer == 10000000000 else answer)