def GCD(x,y):
    if y == 0:
        return x
    else:
        return GCD(y,x%y)


N = int(input())
if N == 2:
    print(-1)
    exit()
if N == 7:
    ans = [".aaggcc",
           "c..ddee",
           "c..ffgg",
           "hij...",
           "hij...",
           "klm...",
           "klm..."]
    for i in ans:
        print("".join(i))
    exit()
if N == 3:
    print(".aa")
    print("a..")
    print("a..")
    exit()

four = ["aacd",
        "bbcd",
        "efgg",
        "efhh"]
five = ["aabbc",
        "h.iic",
        "hj..d",
        "gj..d",
        "gffee"]
six = ["aacd..",
       "bbcd..",
       "ef..gg",
       "ef..hh",
       "..iikl",
       "..jjkl"]
ans = [list("."*N) for i in range(N)]
a,b,c = [[0,N//5,0],[0,N//5-1,1],[0,N//5-2,2],[2,N//5-1,0],[1,N//5,0]][N%5]
p = 0
for i in range(a):
    for x in range(4):
        for y in range(4):
            ans[p+x][p+y] = four[x][y]
    p += 4

for i in range(b):
    for x in range(5):
        for y in range(5):
            ans[p+x][p+y] = five[x][y]
    p += 5

for i in range(c):
    for x in range(6):
        for y in range(6):
            ans[p+x][p+y] = six[x][y]
    p += 6
for i in ans:
    print("".join(i))