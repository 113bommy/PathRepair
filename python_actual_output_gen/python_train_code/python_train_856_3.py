def l(n,arr):
    s = sorted(arr)
    arr[0],arr[n-1] = arr[n-1],arr[0]
    for i in arr:
        print(i,end=" ")
    
n = int(input())
arr = list(map(int,input().split()))
l(n,arr)