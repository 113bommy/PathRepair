n,m,k = list(map(int,input().split()))
ans = []
x,y = 1,0
while k>1:
    temp = []
    cnt = 2
    if x%2!=0:
        # move L to R
        if y+1<=m:
            temp.append([x,y+1])
            y+=1
            cnt-=1
        else:
            x+=1
            temp.append([x,y])
            cnt-=1
        if x%2!=0:
            # move L to R
            if y+1<=m:
                temp.append([x,y+1])
                y+=1
                cnt-=1
            else:
                x+=1
                temp.append([x,y])
                cnt-=1
        else:
            # move R to L
            if y-1>0:
                y-=1
                temp.append([x,y])
            else:
                x+=1
                temp.append([x,y])
    else:
        if y-1>0:
            y-=1
            temp.append([x,y])
        else:
            x+=1
            temp.append([x,y])

        if x%2!=0:
            # move L to R
            if y+1<=m:
                temp.append([x,y+1])
                y+=1
                cnt-=1
            else:
                x+=1
                temp.append([x,y])
                cnt-=1
        else:
            # move R to L
            if y-1>0:
                y-=1
                temp.append([x,y])
            else:
                x+=1
                temp.append([x,y])
    k-=1
    ans.append(temp)
temp = []
for i in range(x,n+1):
    if i%2!=0:
        for j in range(y+1,m+1):
            temp.append([i,j])
        y = m
    else:
        for j in range(y-1,0,-1):
            temp.append([i,j])
        y = 0
ans.append(temp)
for i in ans:
    print(len(i),end=' ')
    for j in i:
        print(*j,end=' ')
    print()