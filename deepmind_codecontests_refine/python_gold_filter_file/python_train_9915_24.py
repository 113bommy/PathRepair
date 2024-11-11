def isPeak(arr, n, num, i, j): 
    if (i >= 0 and arr[i] > num): 
        return False
    if (j < n and arr[j] > num): 
        return False
    return True


t = int(input())
for _ in range(t):
    n, rl = map(int, input().split())
    arr = list(map(int, input().split()))
    fpeaks = [0]*n
    for i in range(1, n-1):
        if (isPeak(arr, n, arr[i], i-1, i+1)):
            fpeaks[i] = 1

    currmax, maxsofar, length = 0, 0, 0
    sumarr = [[0, sum(fpeaks[:rl]) - fpeaks[0] - fpeaks[rl-1]]]

    maxsofar = 0

    for i in range(1, n-rl + 1):
        tempsum = sumarr[i-1][1]
        sumarr.append( [i, tempsum + fpeaks[i+rl-2] - fpeaks[i]])

    res = 0

    for idx, each in enumerate(sumarr):
        if each[1] > maxsofar:
            res = idx
            maxsofar = each[1]
    
    print(maxsofar + 1, res+1)
