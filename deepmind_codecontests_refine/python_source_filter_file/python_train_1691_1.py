
numcases = int(input())

def isPossible(arr, n):
    p1 = arr[0]
    p2 = 0
    count = 0
    for i in range(n - 1):
        if arr[i + 1] - arr[i] == 1:
            continue
        elif arr[i + 1] < arr[i]:
            count = count + 1
            if count > 1:
                if p1 - arr[i] == 1:
                    p1 = p2
                    p2 = i + 1
                    continue
                else:
                    return "No"
            else:
                p2 = arr[i + 1]
        else:
            return "No"
    return "Yes"
for i in range(numcases):
    n = int(input())
    arr = list(map(int, input().split()))
    print(isPossible(arr, n))