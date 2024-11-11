n,temp = map(int,input().split())
val = 0
arr = [[val for i in range(n)] for j in range(n)]
for i in range(n):
    arr[i][i]=temp
    
for i in range(n):
    for j in range(n):
        print(arr[i][j],end='')
    print("")
