import math
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))

    temp = sorted(arr)
    if all(x==-1 for x in arr):
        print("0 1")
        continue
    pairs = []
    for i in range(n):
        if arr[i] == -1:
            if i-1>=0 and arr[i-1] != -1:
                pairs.append(arr[i-1])
            if i+1<n and arr[i+1] != -1:
                pairs.append(arr[i+1])
#             if i>0 and i<n-1:
#                 pairs.append(arr[i-1])
#                 pairs.append(arr[i+1])
#             elif i==0:
#               iiiijjj  pairs.append(arr[i+1])
#             elif i==n-1:
#                 pairs.append(arr[i-1])
#     print(pairs)
    if len(pairs)==1:
        print(0,end = " ")
        print(pairs[-1])
        continue
    mn = min(pairs)
    mx = max(pairs)
    val = (mn+mx)//2
    for i in range(n):
        if arr[i] == -1:
            arr[i] = val
#     print(arr)
    mn = 0
    for i in range(n-1):
        mn = max(mn,abs(arr[i]-arr[i+1]))
    print(mn,end = " ")
    print(val)


            
