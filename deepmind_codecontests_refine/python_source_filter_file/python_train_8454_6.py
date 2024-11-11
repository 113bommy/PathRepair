def get_non_zero_distance(arr):
    zeros = 0

    for i in range(len(arr)):
        if arr[i] == 0:
            zeros += 1
            arr[i] = 1

    sum_v = sum(arr)

    if sum_v != 0:
        return zeros
    else:
        while sum_v != 0:
            sum_v += 1
            zeros +=1

        return zeros


n = int(input())

for _ in range(n):
    i = int(input())
    arr = list(map(int, input().split()))

    print(get_non_zero_distance(arr))