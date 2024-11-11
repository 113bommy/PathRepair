n,m = [int(i) for i in input().split()]
array = [int(i) for i in input().split()]

def bins(a, b):
    if a == b:
        return a
    mid = (a+b)//2
    if good(mid):
        return bins(a, mid)
    else:
        return bins(mid+1, b)

def good(k):
    arr = array[:]
    if arr[0] + k >= m:
        arr[0] = 0
    for i in range(1, n):
        if arr[i] < arr[i-1]:
            if arr[i-1] - arr[i] > k:
                return False
            else:
                arr[i] = arr[i-1]
        else:
            if arr[i] + k - n >= arr[i-1]:
                arr[i] = arr[i-1]
    return True






print(bins(0, m))