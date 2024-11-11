t=int(input())
while(t>0):
    n,m=map(int,input().split())
    ans=[]
    for i in range(0,n):
        temp=['B']
        if(i!=(n-1)):
            for j in range(1,m):
                temp.append('W')
            ans.append(temp)
        else:
            for j in range(1,m):
                temp.append('B')
                ans.append(temp)
        #if(i==(n-1) and m!=2):
        #    ans[i][1]='W'
    for i in range(n):
        for j in range(m):
            print(ans[i][j],end='')
        print()
    t-=1