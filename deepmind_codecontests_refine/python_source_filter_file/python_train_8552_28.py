n=int(input())
arr=list(map(int,input().split()))
if sum(arr[:len(arr)//2])!=sum(arr[len(arr)//2:]):
    print(arr)
else:
    arr.sort()
    if sum(arr[:len(arr)//2])!=sum(arr[len(arr)//2:]):
        print(arr)
    else:
        print(-1)