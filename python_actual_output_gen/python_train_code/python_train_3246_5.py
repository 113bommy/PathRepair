n = int(input())
inter = [[False]*n]*2
for i in range(n*n):
    h,v = input().split()
    hnum = int(h)-1
    vnum = int(v)-1
    if not inter[0][hnum] and not inter[1][vnum]:
        inter[0][hnum] = True
        inter[1][vnum] = True
        print(i+1,end=' ')