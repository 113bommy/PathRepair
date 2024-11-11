n,m,k = map(int,input().split(' '))
M = [[0 for j in range(m-1)] for i in range(n-1)]
C = [[False for j in range(m)] for i in range(n)]
ans = -1
ansCnt = False
for w in range(k):
    x,y = map(int,input().split(' '))
    x-=1
    y-=1
    if  C[x][y] == False  &  ansCnt == False:
        C[x][y] = True
        for i in [0,-1]:
            for j in [0,-1]:
                if (x + i > -1) & (y + j > -1) & (x + i < n - 1) & (y + j < m - 1):
                    M [x+i][y+j] += 1
                    if M [x+i][y+j] == 4:
                          ans = w+1
                          ansCnt = True
print(ans)
    
                            
                                                
