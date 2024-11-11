for _ in range(int(input())):
    number = int(input())
    work = list(map(int,input().split()))
    result = list(map(int,input().split()))
    if work == result:
        print("YES")
        continue
    i = 0
    while work[i] == result[i]:
        i += 1
    l = i
    while i<number:
        if work[i] != result[i]:
            r = i
        i += 1
    k = result[l] - work[l]
    if k<0:
        print("NO")
        continue 
    go = True
    while l < r:
        work[l] = work[l] + k
        if work[l] != result[l]:
            print("NO")
            go = False
            break
        l += 1
    if go:
        print("YES")  