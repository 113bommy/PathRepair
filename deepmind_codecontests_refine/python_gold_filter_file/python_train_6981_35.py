h = [ [ [ 0 for x in range(0, 10) ] for y in range(0, 3) ] for z in range(0, 4) ]
for i in range(0, int(input())):
    b,f,r,v = map(int, input().split())
    h[b-1][f-1][r-1] += v
c = 1
for x in h:
    for y in x:
        print(" " + " ".join(map(str, y)))
    if c < 4:
        print("#" * 20)
    c += 1