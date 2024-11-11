def helper(n,m,k):
    
    if k % 2 == 1:
        res = [[-1] * m for i in range(n)]
        return res
    
    k = k // 2
    
    pool = [[[0]*m for i in range(n)] for j in range(k+1)]
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    for t in range(1,k+1):
        for i in range(n):
            for j in range(m):
                tres = [9999999] * 4
                for c in range(4):
                    if 0 <= i+dx[c] < n and 0 <= j+dy[c] < m:
                        if c == 0:
                            tres[c] = hedge[i][j]*2 + pool[t-1][i+dx[c]][j+dy[c]]
                        elif c == 1:
                            tres[c] = hedge[i][j-1]*2 + pool[t-1][i+dx[c]][j+dy[c]]
                        elif c == 2:
                            tres[c] = vedge[i][j]*2 + pool[t-1][i+dx[c]][j+dy[c]]
                        else:
                            tres[c] = vedge[i-1][j]*2 + pool[t-1][i+dx[c]][j+dy[c]]
                pool[t][i][j] = min(tres)
    print(pool)

    return pool[k]

#t = int(input())
#for i in range(t):
#n = int(input())
n,m,k = map(int,input().split(" "))
hedge = []
vedge = []
for i in range(n):
    hedge.append(list(map(int,input().split(" "))))
for i in range(n-1):
    vedge.append(list(map(int,input().split(" "))))
#a = list(map(int,input().split(" ")))
#print(len(a))
res = helper(n,m,k)
for j in range(len(res)):
    print(" ".join(map(str,res[j])))
#print(res)