def calc(arr,n):
    flag=False
    print(arr)
    for i in range(n):
        for j in range(n):
            if i+1<n and j+1<n:
                if arr[i][j]=='1' and arr[i+1][j]=='0' and arr[i][j+1]=='0':
                    # print(i,j)
                    flag=True
    if flag:
        return "NO"
    else:
        return "YES"
t=int(input())
for i in range(t):
    n=int(input())
    arr=[]
    for i in range(n):
        arr.append(list(input()))
    print(calc(arr,n))
