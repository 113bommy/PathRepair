def Super(n, arr):
    left=False
    right = False
    lower = False
    upper = False
    count = 0
    for i in range(n):
        for j in range(n):
            if arr[i][0]<arr[j][0] and arr[i][1] == arr[j][1]:
                left = True
            if arr[i][0]>arr[j][0] and arr[i][1] == arr[j][1]:
                right = True
            if arr[i][0]==arr[j][0] and arr[i][1] > arr[j][1]:
                upper = True
            if arr[i][0]==arr[j][0] and arr[i][1] < arr[j][1]:
                lower = True
        if left and right and lower and upper:
            count += 1
        left = False
        right = False
        lower = False
        upper = False
    print(count)
                
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
Super(n,arr)