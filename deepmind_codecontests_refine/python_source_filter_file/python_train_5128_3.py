n,k = map(int,input().split())
a = list(map(int,input().split()))
aOrderSorter = []
aOrderList = []
for i in range(n):
    aOrderSorter.append((a[i],i))
    aOrderList.append(-1)
aOrderSorter.sort(key = lambda x:x[0])
for i in range(n):
    aOrderList[aOrderSorter[i][1]] = i
if k % 2 == 0:
    k = k // 2
    oddMin = -1
    evenMin = -1
    # Finding oddMin, not allowing the last element
    l = 0
    r = k
    while r != l:
        m = (r + l) // 2
        subseq = []
        subseqLen = 0
        for i in range(n):
            if i == n-1:
                break
            if aOrderList[i] < k + m and (subseqLen == 0 or subseq[subseqLen - 1] != i-1):
                subseq.append(i)
                subseqLen += 1
                if subseqLen >= k:
                    break
        if subseqLen >= k:
            r = m
        else:
            l = m + 1
    oddMin = r

    # Finding evenMin, not allowing the first element
    l = 0
    r = k
    while r != l:
        m = (r + l) // 2
        subseq = []
        subseqLen = 0
        for i in range(n):
            if i == 0:
                continue
            if aOrderList[i] < k + m and (subseqLen == 0 or subseq[subseqLen - 1] != i-1):
                subseq.append(i)
                subseqLen += 1
                if subseqLen >= k:
                    break
        if subseqLen >= k:
            r = m
        else:
            l = m + 1
    evenMin = r

    print(aOrderSorter[k + min(oddMin,evenMin) - 1][0])

else:
    k = k // 2
    # Finding oddMin, requiring k + 1 elements
    l = 1
    r = k + 2
    while r != l:
        m = (r + l) // 2
        subseq = []
        subseqLen = 0
        for i in range(n):
            if aOrderList[i] < k + m and (subseqLen == 0 or subseq[subseqLen - 1] != i-1):
                subseq.append(i)
                subseqLen += 1
                if subseqLen >= k:
                    break
        if subseqLen >= k + 1:
            r = m
        else:
            l = m + 1
    oddMin = r

    # Finding evenMin, not allowing the first element and the last element
    l = 0
    r = k
    while r != l:
        m = (r + l) // 2
        subseq = []
        subseqLen = 0
        for i in range(n):
            if i == 0:
                continue
            if i == n-1:
                break
            if aOrderList[i] < k + m and (subseqLen == 0 or subseq[subseqLen - 1] != i-1):
                subseq.append(i)
                subseqLen += 1
                if subseqLen >= k:
                    break
        if subseqLen >= k:
            r = m
        else:
            l = m + 1
    evenMin = r

    print(aOrderSorter[k + min(oddMin,evenMin) - 1][0])

        

