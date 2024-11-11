t = int(input())
for __ in range(t):
    n, m = map(int, input().split(' '))
    arr = [int(val) for val in input().split(' ')]
    x = [int(val) for val in input().split(' ')]

    stack = []
    csum = 0
    cmax = 0
    for a in arr:
        csum += a
        cmax = max(cmax, csum)
        stack.append(cmax)

    res = [0]*m
    for i, y in enumerate(x):
        if csum <= 0:
            if y > cmax:
                res[i] = -1
            else:
                left = 0
                right = len(stack)
                while left < right:
                    mid = (left+right)//2
                    if stack[mid] >= y:
                        right = mid
                    else:
                        left = mid+1
                res[i] = left
        else:
            num_req = max(0,(y-stack[-1]+csum-1) // csum)
            left = 0
            right = len(stack)
            while left < right:
                mid = (left+right)//2
                if stack[mid] >= y-csum*num_req:
                    right = mid
                else:
                    left = mid+1
            res[i] = num_req*n+left
        print(' '.join(map(str,res)))
