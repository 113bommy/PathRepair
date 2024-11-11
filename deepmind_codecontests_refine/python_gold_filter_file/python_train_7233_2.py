from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int, stdin.readline().split()))
def fn(row):
    cnt = res = 0
    for j in range(c):
        if a[row][j] == 1:
            cnt += 1
        else:
            cnt = 0
        res = max(cnt, res)
    return res
for _ in range(1):#nmbr()):
    r,c,q=lst()
    a=[lst() for _ in range(r)]
    l=[fn(i) for i in range(r)]
    for _ in range(q):
        x,y=lst()
        a[x-1][y-1]^=1
        cnt = res= 0
        for j in range(c):
            if a[x-1][j] == 1:cnt += 1
            else:cnt = 0
            res = max(cnt, res)
        l[x-1]=res
        print(max(l))