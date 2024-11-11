def func(length, prime):
    nums = sorted(map(int, input().split()))
    mini = max(nums[0], nums[-1]-length+1)

    xs = list(range(mini, min(mini+length, nums[-1]+1)))
    L = len(xs)  # candidates, 0~L-length

    idxs = [0] * length
    for i in range(L-1, -1, -1):
        if xs[i] == nums[-1]:
            idxs[-1] = length-i
            break

    for i in range(length-2, -1, -1):
        diff = nums[i+1]-nums[i]
        idxs[i] = min(length, idxs[i+1]+diff)

    for i in range(length):
        idxs[i] -= (length-1-i)
    
    from collections import defaultdict
    num2i = defaultdict(set)

    flag = False
    for i, n in enumerate(idxs):
        if n == i+1:
            if n % prime == 0:
                flag = True
                break
        else:
            num2i[n].add(i)

    res = []
    for x in xs:
        if flag:
            break
        if all(x%prime!=0 for x in num2i):
            res.append(x)
        num2i = {n+1:s for n, s in num2i.items()}
        for k in list(num2i.keys()):
            v = num2i[k]
            if k-1 in v:
                v.remove(k-1)
                if k % prime == 0:
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
