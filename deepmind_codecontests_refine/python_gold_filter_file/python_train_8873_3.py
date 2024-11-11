t=int(input())
for _ in range(0,t):
    n=int(input())
    arr=[]
    for _ in range(0,n):
        arr.append(input())
    grid=[]
    for i in range(0,len(arr)):
        temp=arr[i]
        asd=[]
        for j in range(0,len(temp)):
            asd.append(temp[j])
        grid.append(asd)
  
    ans=True
    for i in range(n-2,-1,-1):
        for j in range(n-2,-1,-1):
            if grid[i][j]=="1" and grid[i+1][j]=="0" and grid[i][j+1]=="0":
                ans=False
                break
    if ans:
        print("YES")
    else:
        print("NO")
