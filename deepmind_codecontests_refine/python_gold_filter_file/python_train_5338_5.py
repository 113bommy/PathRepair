def solve(n, arr):
    if n <= 2:
        print(0)
        print(*arr)
        return

    arr.sort()
    arr1 = [0]
    dic = {0:arr[0]}
    cur = 0
    for i in range(1, n):
        if arr[i] == arr[i-1]:
            arr1.append(cur)
        else:
            cur += 1
            dic[cur] = arr[i]
            arr1.append(cur)
    
    if arr[-2] == 0:
        print(0)
        print(*arr)
        return
    
    count = [0]
    cur = 0
    for a in arr1:
        if a == cur:
            count[-1] += 1
        else:
            cur += 1
            count.append(1)
    count = count[::-1]
    suff = [0]
    for x in count:
        suff.append(suff[-1] + x)
    suff.pop()
    suff = suff[::-1]
    
    i = 0
    while suff[arr1[i]] >= i + 2:
        i += 1
    k = i
    
    res = [-1 for i in range(n)]
    for i in range(k):
        res[i*2+1] = dic[arr1[i]]
    j = k
    for i in range(n):
        if res[i] == -1:
            res[i] = dic[arr1[j]]
            j += 1
            
    print(k)
    print(*res)


n = int(input())
arr = list(map(int, input().split()))
solve(n, arr) 