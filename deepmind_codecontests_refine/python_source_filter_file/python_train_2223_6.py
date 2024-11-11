def func(a,b):
    #print("func",a,b)
    q = []
    q += [[a,b]]
    for [ita,itb] in q:
        area[ita][itb] = 0
        #print(ita,itb)
        for i in range(1,1001):
            if area[i][itb] == 1 and i !=ita:
                q += [[i,itb]]
        for j in range(1,1001):
            if area[ita][j] == 1 and j !=itb:
                q += [[ita,j]]



n = int(input())
ans = 0
area = [[0 for i in range(1001)] for j in range(1001)]
for i in range (n):
    [a,b] = [int(i) for i in input().split()]
    area[a][b] = 1

for i in range (1,10):
    for j in range(1,10):
        if area[i][j] == 1:
            ans += 1
            func(i,j)
print(ans - 1)
