n = int(input())

nums = [int(x) for x in input().split()]

missing = set([x for x in range(1,n+1)])

if nums.count(0) == n:
    if n == 1:
        print(0)
    else:
        print(1)

else:
    for x in nums:
        if x != 0:
            missing.remove(x)

    odds = 0
    evens = 0

    for x in missing:
        if x%2 == 0:
            evens += 1
        else:
            odds += 1

    gaps = []
    gaps2 = []

    ind = 0

    if nums[0] == 0:
        left = -1
        leftInd = 0
        while nums[ind] == 0:
            ind += 1
        rightInd = ind
        right = nums[ind]%2

        gaps2.append([rightInd-leftInd, left, right])

    if nums[-1] == 0:
        right = -1
        rightInd = n
        while nums[n-1] == 0:
            n -= 1
        leftInd = n-1
        left = nums[n-1]%2
        gaps2.append([rightInd-leftInd, left, right])
    
    while ind < n:
        if nums[ind] == 0:
            left = nums[ind-1]%2
            leftInd = ind
            while nums[ind] == 0:
                ind += 1
            rightInd = ind
            right = nums[ind]%2
            gaps.append([rightInd-leftInd, left, right])
        else:
            ind += 1

    #print(gaps)
    gaps.sort()

    total = 0
    
    for x in range(n-1):
        if nums[x] != 0 and nums[x+1] != 0 and nums[x]%2 != nums[x+1]%2:
            total += 1

    for x in range(len(gaps)-1,-1,-1):
        if gaps[x][1] + gaps[x][2] == 1:
            gaps.pop(x)
            total += 1


    def best(gaps,odd,even):
        total = 0
        for l, ty, ty2 in gaps:
            if ty == 1:
                if odd >= l:
                    odd -= l
                else:
                    total += 2
            else:
                if even >= l:
                    even -= l
                else:
                    total += 2
        return total

    first = total + best(gaps,odds, evens)+len(gaps2)
    for x in gaps2:
        if x[1] == 1 or x[2] == 1:
            if odds >= x[0]:
                first = min(first,total + best(gaps,odds-x[0], evens)+len(gaps2)-1)
        else:
            if evens >= x[0]:
                first = min(first,total + best(gaps,odds, evens-x[0])+len(gaps2)-1)
    if len(gaps2) == 2:
        newOdd = odds
        newEven = evens
        if gaps2[0][2] == 1:
            newOdd -= gaps2[0][0]
        else:
            newEven -= gaps2[0][0]

        if gaps2[1][1] == 1:
            newOdd -= gaps2[1][0]
        else:
            newEven -= gaps2[1][0]

        if newOdd >= 0 and newEven >= 0:
            first = min(first, total + best(gaps, newOdd, newEven))
    print(first)
