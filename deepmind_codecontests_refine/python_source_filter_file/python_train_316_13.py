import sys
lines=sys.stdin.readlines()
for line in lines:
    H,W=map(int,line.split())
    if H == W == 0: break
    for i in range(H):
        unit='#.' if i % 2 == 0 else '.#'
        print((unit*(W+1)//2)[1:W])
    print('')