def sol(arr,n):

    sec = arr[0] + 1
    for i in range(1,n):
        if arr[i - 1] <= arr[i]:
            sec += 2 + (arr[i] - arr[i-1])
        else:
            sec += arr[i-1] - arr[i] + 2

    print(sec)
    return

n = int(input())
arr = []
for t in range(n):
    arr.append(int(input()))
sol(arr,n)