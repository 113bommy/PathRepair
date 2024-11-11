for i in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    for j in range(1,n//2+1):
        print(arr[0],arr[j])
