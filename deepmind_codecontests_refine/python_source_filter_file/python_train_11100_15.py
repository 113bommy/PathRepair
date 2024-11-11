n, k = map(int, input().split())
a = [int(x) for x in input().split()]
if k>n-1:
    print(max(a))
else:
    count = 0
    i = 0
    j = 1
    found = False
    while(i<n and j<n):
        if a[i]>a[j]:
            count += 1
            j += 1
        else:
            count = 0
            i = j
            j += 1
        if count == k:
            found = True
            break
    if found:
        print(a[i])
    else:
        print(max(a))
