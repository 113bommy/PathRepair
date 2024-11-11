def solver(arr):
    k = len(arr)-1
    if arr[0]+arr[1]<arr[k]:
        return [0+1,1+1,k+1]
    else:
        return [-1]

for t in range(int(input())):
    _ = int(input())
    arr = list(map(int,input().split()))
    for i in solver(arr):
        print(i,end=' ')
    print()