n,k=map(int,input().split())
print("YES")
arr=[]
for i in range(4):
    arr.append([])
    for j in range(n):
        arr[i].append("")
if k%2==0:
    for j in range(n):
        for i in range(4):
            if i==0 or i==3 or j==0 or j==n or k==0:
                arr[i][j]="."
            else:
                arr[i][j]="#"
                k-=1
else:
    for j in range(n):
        for i in range(4):
            arr[i][j]="."
    if k>n-2:
        tt=n-2
        tt=tt//2
        arr1=["."]+["."]*((n-3)//2-tt)+['#']*tt+['#']+['#']*tt+["."]*((n-3)//2-tt)+["."]
        arr[1]=arr1.copy()
        k-=n-2
        tt=k
        tt=tt//2
        arr1=["."]+["."]*((n-3)//2-tt)+['#']*tt+['.']+['#']*tt+["."]*((n-3)//2-tt)+["."]
        arr[2]=arr1.copy()
    else:
        tt=k-1
        tt=tt//2
        arr1=["."]+["."]*((n-3)//2-tt)+['#']*tt+['#']+['#']*tt+["."]*((n-3)//2-tt)+["."]
        arr[1]=arr1.copy()
for i in range(4):
    for j in range(n):
        print(arr[i][j],end="")
    print("")    


        