cases = int(input())
for i in range(cases):
    n = int(input())
    l2 = input().split(' ')
    arr = []
    for a in l2:
        arr.append(int(a))
    moves = 0
    test = arr[:]
    test.sort()
    if test == arr:
        print(0)
        print('')
        continue
    sample = []
    for j in range(n):
        sample.append(j)
    unfix = []
    miss = -1
    for l in range(len(arr)):
        ele1 = arr[l]
        ele2 = sample[l]
        if ele1 != ele2:
            unfix.append(l)
    index = []
    while arr!=sample:    
        for k in range(n+1):
            if k not in arr:
                miss = k
                if miss == n:
                    rand = unfix[0]
                    index.append(str(rand))
                    arr[rand] = n
                    moves += 1
                    break
                elif miss < n:
                    arr[miss] = miss
                    index.append(str(miss))
                    unfix.remove(miss)
                    moves += 1
                    break
    print (moves)
    print (' '.join(index))

