n=int(input())
arr=[int(i) for i in input().split()]
if len(arr) < 3:
    print(len(arr))
else:
    maximum = 2
    count = 0
    for i in range(2, len(arr)):
        if arr[i-1]+arr[i-2] == arr[i]:
            count+=1
        else:
            if count > maximum:
                maximum = count
                maximum+=2
            count = 0
    if count > maximum:
        maximum = count
        maximum+=2
    print(maximum)