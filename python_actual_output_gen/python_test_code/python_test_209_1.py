L = [int(s) for s in input().split()]
n, d, h = L[0], L[1], L[2]

if d > 2*h or d < h or (d==1 and h==1):
    print(-1)
else:
    for i in range(h):
        print("%d %d" % (i+1,i+2))
    if d == h:
        for j in range(n-1-h):
            print("%d %d" % (2,j+h+2))
    else:
        print("1 %d" % (h+2))
        for j in range(d-h-1):
            print("%d %d" % (j+h+2,j+h+3))
        for k in range(n-d-1):
            print("1 %d" % (d+k+2))