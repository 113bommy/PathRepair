for _ in range(int(input())):
    n,m=map(int,input().split(" "))
    a=[list(map(int,list(input()))) for x in range(n)]
    ans=[]
    def getone(arr):
        for xx in range(2):
            for yy in range(2):
                if arr[xx][yy]==1:
                    return xx,yy
    def getzero(arr):
        for xx in range(2):
            for yy in range(2):
                if arr[xx][yy]==0:
                    return xx,yy
    for x in range(n):
        for y in range(m):
            if x+1<n and  y+1<m:
                temp=list([a[x][y:y+2],a[x+1][y:y+2]])
                sm=0
                for xxx in temp:
                    sm=sm+sum(xxx)
                if sm==0:
                    continue
                if sm==1:
                    xx,yy=getone(temp)
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    tempx=xx
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    yy=(yy+1)%2
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    a[x][y]=0
                    a[x+1][y]=0
                    a[x][y+1]=0
                    a[x+1][y+1]=0
                elif sm==3:
                    for xx in range(2):
                        for yy in range(2):
                            if temp[xx][yy]==1:
                                ans.append([x+1+xx,y+1+yy])
                    a[x][y]=0
                    a[x+1][y]=0
                    a[x][y+1]=0
                    a[x+1][y+1]=0
                elif sm==4:
                    for xx in range(2):
                        for yy in range(2):
                            if temp[xx][yy]==1:
                                ans.append([x+1+xx,y+1+yy])
                    ans.pop()
                    xx,yy=1,1
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    tempx=xx
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    yy=(yy+1)%2
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    a[x][y]=0
                    a[x+1][y]=0
                    a[x][y+1]=0
                    a[x+1][y+1]=0
                elif sm==2:
                    for xx in range(2):
                        for yy in range(2):
                            if temp[xx][yy]==1:
                                ans.append([x+1+xx,y+1+yy])
                    xx,yy=getzero(temp)
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    tempx=xx
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    yy=(yy+1)%2
                    xx=(xx+1)%2
                    ans.append([x+1+xx,y+1+yy])
                    ans.append([x+1+(xx+1)%2,y+1+yy])
                    ans.append([x+1+xx,y+1+(yy+1)%2])
                    a[x][y]=0
                    a[x+1][y]=0
                    a[x][y+1]=0
                    a[x+1][y+1]=0

    print(len(ans)//3)
    cnt=0
    for x in range(len(ans)):
        print(*ans[x],end=" ")
        cnt+=1
        if cnt==3:
            print()
            cnt=0




                    






                                
                    



