def merge(arr, temp, left, mid, right):
    inv_count = 0

    i = left
    j = mid
    k = left
    while ((i <= mid - 1) and (j <= right)):
        if (arr[i] <= arr[j]):
            temp[k] = arr[i]
            k += 1
            i += 1
        else:
            temp[k] = arr[j]
            k += 1
            j += 1
            inv_count = inv_count + (mid - i)
    while (i <= mid - 1):
        temp[k] = arr[i]
        k += 1
        i += 1

    while (j <= right):
        temp[k] = arr[j]
        k += 1
        j += 1

    for i in range(left, right + 1, 1):
        arr[i] = temp[i]

    return inv_count

def _mergeSort(arr, temp, left, right):
    inv_count = 0
    if (right > left):

        mid = int((right + left) / 2)

        inv_count = _mergeSort(arr, temp, left, mid)
        inv_count += _mergeSort(arr, temp, mid + 1, right)
        inv_count += merge(arr, temp, left, mid + 1, right)
    return inv_count
def countSwaps(arr, n):
    temp = [0 for i in range(n)]
    return _mergeSort(arr, temp, 0, n - 1)

for test in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    if countSwaps(arr, n) < (n * (n - 1) // 2 - 1):
        print("YES")
    else:
        print("NO")

