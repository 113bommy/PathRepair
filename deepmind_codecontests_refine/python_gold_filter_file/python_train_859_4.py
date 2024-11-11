ans = []

def doRev(arr):
    # print("REVERSE")
    preAns = [len(arr), *([1]*len(arr))]
    ans.append(preAns)
    return list(reversed(arr))

def do(arr, splits):
    splits.append(len(arr))
    splits = list(set(splits))
    splits.sort()
    preAns = [len(splits)]
    l = 0
    for i in range(len(splits)):
        preAns.append(splits[i]-l)
        l = splits[i]
    ans.append(preAns)
    # print(splits, preAns)
    newArr = []
    l = 0
    for i in range(len(splits)):
        newArr.append(arr[l:splits[i]])
        l = splits[i]

    # print(newArr, "How we split it")
    newArr.reverse()
    new = []
    for i in range(len(newArr)):
        for g in range(len(newArr[i])):
            new.append(newArr[i][g])
    # print(new, "what we got")
    # print()
    return new

def doinotherway(arr):
    n = len(arr)
    arr = arr
    it = 0
    while it < n+10:
        it += 1
        f = arr[0]
        if f == 1:
            if arr == list(reversed(list(sorted(arr)))):
                arr = doRev(arr)
            else:
                more = 0
                for i in range(1, n):
                    if arr[i] == arr[i - 1] + 1:
                        more += 1
                    else:
                        break
                arr = do(arr, [more + 1])
        else:
            more = 0
            for i in range(1, n):
                if arr[i] != arr[i - 1] + 1:
                    break
                else:
                    more += 1
            ind = 0
            for i in range(n):
                if arr[i] == f - 1:
                    ind = i
                    break
            more2 = 0
            for i in range(ind - 1, -1, -1):
                if arr[i] != arr[i + 1] - 1:
                    break
                else:
                    more2 += 1

            arr = do(arr, [ind - more2, ind + 1])

        if arr == list(reversed(list(sorted(arr)))):
            arr = doRev(arr)
        if arr == list(sorted(arr)):
            break
        # print(arr,'NEW ARRAY---------------------')
    # print(arr, 'FIN')
    # print(arr)

def donormal(arr):
    n = len(arr)
    arr = arr
    it = 0
    while it < n+10:
        it += 1
        f = arr[0]
        if f == n:
            if arr == list(reversed(list(sorted(arr)))):
                arr = doRev(arr)
            else:
                more = 0
                for i in range(1, n):
                    if arr[i] == arr[i - 1] - 1:
                        more += 1
                    else:
                        break
                arr = do(arr, [more + 1])
        else:
            more = 0
            for i in range(1, n):
                if arr[i] != arr[i - 1] - 1:
                    break
                else:
                    more += 1
            ind = 0
            for i in range(n):
                if arr[i] == f + 1:
                    ind = i
                    break
            more2 = 0
            for i in range(ind - 1, -1, -1):
                if arr[i] != arr[i + 1] + 1:
                    break
                else:
                    more2 += 1

            arr = do(arr, [ind - more2, ind + 1])

        if arr == list(reversed(list(sorted(arr)))):
            arr = doRev(arr)
        if arr == list(sorted(arr)):
            break
        # print(arr,'NEW ARRAY---------------------')
    # print(arr, 'FIN')
    # print(arr)

def solve():
    n = int(input())
    arr = list(map(int,input().split()))
    c = arr[:]
    if n == 1 or arr == list(sorted(arr)):
        print(0)
        return 0
    donormal(arr)
    global ans
    if len(ans) <=n:
        print(len(ans))
        for i in range(len(ans)):
            print(*ans[i])
    else:
        ans = []
        doinotherway(c)
        print(len(ans))
        for i in range(len(ans)):
            print(*ans[i])

solve()
