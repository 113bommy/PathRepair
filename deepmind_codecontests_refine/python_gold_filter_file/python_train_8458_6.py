for i in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    found=[]
    for i in range(2*n):
        if arr[i] not in found:
            found.append(arr[i])
            print(arr[i],end=" ")
    print("")
