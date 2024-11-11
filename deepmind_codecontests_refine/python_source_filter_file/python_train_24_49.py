def trian(arr):
    if(arr[0]+arr[1]>arr[-1]):
        print(-1)
    else:
        print(1,2,len(arr)-1)
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    (trian(arr))
    