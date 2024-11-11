import bisect


def canBeFormed(n, arr, k):
    sortedArr = sorted(arr)
    found = None
    kVal = 0

    for i in range(n):
        if found is not None:
            if found + 1 < n and sortedArr[found + 1] == arr[i]:
                found += 1
            else:
                found = bisect.bisect_left(sortedArr, arr[i])
                # print('found: ', found, ' val: ', arr[i])
                kVal += 1
        else:
            found = bisect.bisect_left(sortedArr, arr[i])
            # print('found: ', found, ' val: ', arr[i])
            kVal += 1

    # print(kVal, k)

    if kVal <= k:
        return True
    return False


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    if canBeFormed(n, arr, k):
        print('Yes')
    else:
        print('No')
