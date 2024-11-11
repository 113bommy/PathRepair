for _ in range(int(input())):
    N=int(input())
    arr=sorted(list(map(int,input().split())))
    for i in range(1,N//2+1):
        print(arr[0],arr[i])
    