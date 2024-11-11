import sys
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, sys.stdin.readline().split() ))
    lst = [0]*n
    curr_max = 0
    for i in range(len(arr)):
        if arr[i] < curr_max:lst[i] = curr_max-arr[i]
        curr_max = max(curr_max, arr[i])
    s = max(lst)
    ans = 0
    while s>0:
        s >>= 1
        ans+=1
    print(ans)