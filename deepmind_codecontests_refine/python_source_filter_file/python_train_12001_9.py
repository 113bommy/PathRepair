tc = int(input())
for _ in range(tc):
    [n, k] = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    narr = sorted(arr)
    i = 1
    top = 0
    while(i<n):
        if(narr[i] < k):
            top += (k-arr[i])//narr[0]
        else:
            break
        i+=1
    print(top)