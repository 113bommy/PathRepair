n = int(input())
arr = list(map(int, input().split()))

if n%2 == 0:
    for i, num in enumerate(arr):
        if num >= 0:
            arr[i] = - 1 - num

else:
    minimum = min(arr)
    maximum = max(arr)
    if minimum >= 0:
        largest_pos = arr.index(maximum)
    else:
        if maximum > (-minimum -1):
            largest_pos = arr.index(maximum)
        else:
            largest_pos = arr.index(minimum)

    for i, num in enumerate(arr):
        if i != largest_pos:
            if num >= 0:
                arr[i] = - 1 - num
        else:
            if num < 0:
                arr[i] = - 1 - num

arr = list(map(str, arr))

print(' '.join(arr))
