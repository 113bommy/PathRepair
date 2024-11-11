from collections import deque
h,w,k = map(int,input().split())
y1,x1,gy,gx = map(int,input().split())
m = ["@"*(w+2)]+["@"+input()+"@" for i in range(h)]+["@"*(w+2)]
opt = [(1,0),(0,1),(-1,0),(0,-1)]
dq=deque([(y1,x1)])
ans = 0
temp = [[-1]*(w+2) for i in range(h+2)]
temp[y1][x1] = 0
cnt = 0
while dq:
    # cnt += 1
    # print(cnt)
    y,x = dq.popleft()
    # print(dq,y,x)
    for j in opt:
        y1 = y+j[0]
        x1 = x+j[1]
        if m[y1][x1] == "@":
            # print(y1,x1,"@@")
            continue
        if temp[y1][x1] == -1 or temp[y1][x1]-temp[y][x]>1:
            for i in range(k):
                if (temp[y1+i*j[0]][x1+i*j[1]] == -1 or temp[y1+i*j[0]][x1+i*j[1]]-temp[y][x]>0) and m[y1+i*j[0]][x1+i*j[1]] == ".":
                    if temp[y1+i*j[0]][x1+i*j[1]]-temp[y][x]==1:
                        continue
                    temp[y1+i*j[0]][x1+i*j[1]] = temp[y][x]+1
                    dq.append((y1+i*j[0],x1+i*j[1]))
                    # print(y1+i*j[0],x1+i*j[1],"a",k,m[y1+i*j[0]][x1+i*j[1]],temp[y1+i*j[0]][x1+i*j[1]])
                else:
                    # print(y1+i*j[0],x1+i*j[1],"b",k,m[y1+i*j[0]][x1+i*j[1]],temp[y1+i*j[0]][x1+i*j[1]])
                    break
# for i in temp:
#     print(i)
# print(temp)
print(temp[gy][gx])