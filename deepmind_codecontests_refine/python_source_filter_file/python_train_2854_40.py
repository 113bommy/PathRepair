n = int(input())
arr = [int(i) for i in input().split()]
myans, pre, i = 0, 0, 0
while i < n:
    if i < 2:
        pre += 1
    else:
        if arr[i-2]+arr[i-1]==arr[i]:
            pre += 1
        else:
            pre = 2
        myans = max(myans, pre)
    i += 1
print("{0}\n".format(myans))
