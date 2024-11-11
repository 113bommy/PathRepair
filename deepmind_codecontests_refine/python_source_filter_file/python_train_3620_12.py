n = int(input())
ans = 10 ** 9
upanddown = [[] for i in range(200001)]
leftandright = [[] for i in range(200001)]
lis = []
for i in range(n):
    x,y,r = map(str,input().split())
    x,y = int(x),int(y)
    lis.append([x+y,x-y,x,y,r])
    if r == "U":
        upanddown[x].append([y,0])
    elif r == "D":
        upanddown[x].append([y,1])
    elif r == "R":
        leftandright[y].append([x,0])
    else:
        leftandright[y].append([x,1])
  # print(upanddown[11])
for li in upanddown:
    if len(li) >= 2:
        li.sort(key=lambda z:z[1])
        li.sort(key=lambda z:z[0])
        key = 0
        keynum = -1
        for num,r in li:
            if r == 0:
                keynum = num
            else:
                if keynum != -1:
                    ans = min(ans,(num-keynum)*5)
for li in leftandright:
    if len(li) >= 2:
        li.sort(key=lambda z:z[1])
        li.sort(key=lambda z:z[0])
        key = 0
        keynum = -1
        for num,r in li:
            if r == 0:
                keynum = num
            else:
                if keynum != -1:
                    ans = min(ans,(num-keynum)*5)
  # print(ans)
lis.sort(key = lambda z:z[2])
lis.sort(key = lambda z:z[0])
for i in range(n-1):
    if lis[i][0] == lis[i+1][0]:
        if (lis[i][4] == "R" and lis[i+1][4] == "U") or (lis[i][4] == "D" or lis[i+1][4] == "L"):
            ans = min(ans,(lis[i+1][2]-lis[i][2])*10)
lis.sort(key = lambda z:z[2])
lis.sort(key = lambda z:z[1])
for i in range(n-1):
    if lis[i][1] == lis[i+1][1]:
        if (lis[i][4] == "U" and lis[i+1][4] == "L") or (lis[i][4] == "R" and lis[i+1][4] == "D"):
            ans = min(ans,(lis[i+1][2]-lis[i][2])*10)
if ans == 10 ** 9:
    print("SAFE")
else:
    print(ans)