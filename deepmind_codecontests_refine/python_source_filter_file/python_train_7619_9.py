r,c=tuple(map(int,input().split()))
arr=[]
for _ in range(r):
    arr.append(list(map(int,input().split())))
flag=0
for i in range(r-2,0,-1):
    j=c-1
    while(j>=0):
        if arr[i][j]==0:
            if(arr[i+1][j]-arr[i-1][j]<=1 or arr[i][j+1]-arr[i][j-1]<=1 or arr[i+1][j]-arr[i][j-1]<=1 or arr[i][j+1]-arr[i-1][j]<=1):
                flag=1
                break
            else:
                arr[i][j]=min(arr[i][j+1],arr[i+1][j])-1
        j-=1
    if (flag):
        break
if(flag):
    print(-1)
else:
    flag=0
    for i in range(r):
        for j in range(c-1):
            if(arr[i][j]<=arr[i][j+1]):
                flag=1
                break
    for i in range(c):
        for j in range(r-1):
            if flag:
                break
            else:
                if(arr[j][i]>=arr[j+1][i]):
                    flag=1
                    break
    if(flag):
        print(-1)
    else:
        s=0
        for i in arr:
            s+=sum(i)
        print(s)