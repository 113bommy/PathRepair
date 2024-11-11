import sys
input = sys.stdin.readline
n,k = list(map(int,input().split())) 
m = [None]*n
d1 = [[0,1],[0,-1]]
d2 = [[1,0],[-1,0]]
#ans = [[0]*n for _ in range(n)]
 
for i in range(n):
    m[i] = input()
max_num = 0
res = [0,0]
for i in range(n):
    for j in range(n):
        if m[i][j]!='.':
            continue
        tmp = 0
        cnt = 1
        for x in d1:
            for z in range(1,k):
                if 0<=i+x[0]*z<n and 0<=j+x[1]*z<n and m[i+x[0]*z][j+x[1]*z]=='.':
                    cnt += 1
                else:
                    break
        tmp += max(cnt-k+1,0)
        #ans[i][j] += max(cnt-k+1,0)
        cnt = 1
        for x in d2:
            for z in range(1,k):
                if 0<=i+x[0]*z<n and 0<=j+x[1]*z<n and m[i+x[0]*z][j+x[1]*z]=='.':
                    cnt += 1
                else:
                    break
        tmp += max(cnt-k+1,0)
        #ans[i][j] += max(cnt-k+1,0)
        if tmp > max_num:
            res = [i+1,j+1]
            max_num = tmp
print(*res)