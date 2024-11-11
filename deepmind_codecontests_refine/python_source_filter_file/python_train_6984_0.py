n,m = map(int,input().split())
arr = []
for i in range(n):
    arr.append(list(input()))

vis = {}

ans = []
for i in range(1,n-1):
    for j in range(1,m-1):
        if arr[i][j] == "*":
            # w,x,y,z = (i,j),(i,j),(i,j),(i,j)
            if arr[i+1][j] == "*" and arr[i-1][j] == "*" and arr[i][j+1] == "*" and arr[i][j-1] == "*":
                w,x,y,z = [i+1,j],[i-1,j],[i,j+1],[i,j-1]
                vis[(i,j)] = 1
                #print(vis)
                while True:
                    #print(w,x,y,z)
                    if w[0] >= n or (w[0] < n and arr[w[0]][w[1]] != "*"):
                        break
                    else:
                        w[0] += 1
                    if x[0] < 0 or (x[0] >= 0 and arr[x[0]][x[1]] != "*"):
                        break
                    else:
                        x[0] -= 1
                    if y[1] >= m or (y[1] < m and arr[y[0]][y[1]] != "*"):
                        break
                    else:
                        y[1] += 1
                    if z[1] < 0 or (z[1] >= 0 and arr[z[0]][z[1]] != "*"):
                        break
                    else:
                        z[1] -= 1
                    vis[(w[0]-1,w[1])] = 1
                    vis[(x[0]+1,x[1])] = 1
                    vis[(y[0],y[1]-1)] = 1
                    vis[(z[0],z[1]+1)] = 1
                ans.append([i+1,j+1,min(w[0] - i - 1,i - x[0]-1,y[0] - j - 1,j - y[1] - i)])
flag = True
#print(vis)
for i in range(n):
    for j in range(m):
        if arr[i][j] == "*" and (i,j) not in vis:
            #print(i,j)
            flag = False
            break

if not flag:
    print(-1)
else:
    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])