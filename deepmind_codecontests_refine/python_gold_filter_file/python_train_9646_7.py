from math import ceil, sqrt

num = input()
n = len(num)
lim = ceil(sqrt(2 * 10**9))
nums = [str(int(i**2)) for i in range(lim, 0, -1)]
for sq in nums:
    if len(sq) > n:
        continue
    ind = 0
    for dig in sq:
        ind = num.find(dig, ind, n)
        if ind == -1:
            break
        else:
            ind += 1
    else:
        print(n - len(sq))
        break
else:
    print(-1)
