def func(length, prime):
    nums = sorted(map(int, input().split()))
    mini = max(nums[0], nums[-1]-length+1)
    maxi = min(mini+length, nums[-1]+1)

    L = maxi-mini  # candidates, 0~L-length

    idxs = [0] * length
    for i in range(L-1, -1, -1):
        if mini+i == nums[-1]:
            idxs[-1] = length-i
            break


    for i in range(length-2, -1, -1):
        diff = nums[i+1]-nums[i]
        idxs[i] = min(length, idxs[i+1]+diff)

    for i in range(length):
        idxs[i] -= (length-1-i)

    # print(idxs)

    from collections import defaultdict
    num2i = defaultdict(set)

    bad = [False] * (length+1)
    bad[0] = True
    for i in range(prime, length+1, prime):
        bad[i] = True

    # assert all(x>0 for x in idxs)

    flag = False
    for i, n in enumerate(idxs):
        if n == i+1:
            if bad[n]:
                flag = True
                break
        else:
            num2i[n].add(i)

    # print(num2i)

    res = []
    incri = 0
    for x in range(mini, maxi):
        if flag:
            break
        if not any(bad[k+incri] or k+incri <= 0 for k in num2i.keys()):
            res.append(x)
        incri += 1
        for k in list(num2i.keys()):
            v = num2i[k]
            if k+incri-1 in v:
                v.remove(k+incri-1)
                if bad[k+incri]:
                    flag = True
                    break
                if not v:
                    num2i.pop(k)

    print(len(res))
    print(" ".join(map(str, res)) if res else "")


# cases = int(input())
for i in range(1):
    n, k = map(int, input().split())
    func(n, k)
