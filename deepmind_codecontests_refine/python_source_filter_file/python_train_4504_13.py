t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    arr=[]
    lis=[]
    for i in range(n):
        lis=list(map(int,input().split()))
        arr.append(lis)
    p=0
    k=0
    for i in range(n):
        for j in range(m):
            if i==0 and j==0:
                if arr[i][j]>2:
                    p=1
                    break
                else:
                    arr[i][j]=2
            elif i==n-1 and j==m-1:
                if arr[i][j]>2:
                    p=1
                    break
                else:
                    arr[i][j]=2
                    
            elif i==0 and j<m-1:
                if arr[i][j]>3:
                    p=1
                    break
                else:
                    arr[i][j]=3

            elif j==0 and i<n-1:
                if arr[i][j]>3:
                    p=1
                    break
                else:
                    arr[i][j]=3
                    
            elif i==n-1 and j==0:
                if arr[i][j]>2:
                    p=1
                    break
                else:
                    arr[i][j]=2
                
            elif j==m-1 and i==0:
                if arr[i][j]>2:
                    p=1
                    break
                else:
                    arr[i][j]=2

            elif i==n-1 and j<m-1:
                if arr[i][j]>3:
                    p=1
                    break
                else:
                    arr[i][j]=3

            elif j==m-1 and i<n-1:
                if arr[i][j]>3:
                    p=1
                    break
                else:
                    arr[i][j]=3
            else:
                if arr[i][j]>4:
                    p=1
                    break
                else:
                    arr[i][j]=4
            if p==1:
                break
        if p==1:
            break

        
    if p==1:
        print("NO")
    else:
        print("YES")
        for i in range(n):
            print(arr[i])        
                
                
                
            
                
                
                