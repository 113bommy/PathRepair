for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    avg = sum(arr)/n
    count = dict.fromkeys(arr,0)
    for x in arr:
        count[x] += 1
    arr = list(set(arr))
    if len(arr)==1:
        print((n*(n-1))//2)
        continue
    arr.sort()
    ans = 0
    i, j = 0, len(arr)-1
    while i <= j:
        while (arr[i]+arr[j])/2 > avg:
            j -= 1
        if (arr[i]+arr[j])/2 == avg and i!=j:
            #print(arr[i],arr[j])
            ans += count[arr[i]] * count[arr[j]]
        if i==j and arr[i] == avg:
            l = count[arr[i]]
            ans += l*(l-1)//2
        i += 1
    print(ans)
