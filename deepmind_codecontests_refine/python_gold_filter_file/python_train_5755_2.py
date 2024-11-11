from bisect import *
for _ in range(int(input())):
    n,k = map(int,input().split())
    x,y = sorted(map(int,input().split())),input()
    left = [[0,0,0] for i in range(n)]
    for i in range(n):
        idx = bisect_left(x,x[i]-k)
        left[i][0] = i-idx+1
        left[i][1] = max(left[i-1][0],left[i-1][1]) if i>0 else 0
        left[i][2]=max(left[i-1][2],left[i][0]+left[idx][1]) if idx else max(left[i][0],left[i][1])
    #print(*left)
    print(left[-1][-1])