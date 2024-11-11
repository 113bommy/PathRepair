from math import ceil, floor
def func(x, y):
    if x <= 1000 or y <= 1000:
        ans = 0
        for i in range(2, y + 1):
            ans += min(x // (i + 1), i - 1)
            if i > x:
                return ans
        return ans

    ans = 0
    # cnt = {}
    # xx = 0
    for i in range(2, y + 1):
        if i - 1 >= x // (i + 1):
            # tmp = x // (i + 1)
            # ans += tmp
            # xx += tmp
            # if tmp in cnt: cnt[tmp] += 1
            # if tmp not in cnt: cnt[tmp] = 1
            break
        else:
            tmp = i - 1
            ans += tmp
    # print(i)
    # for i in cnt:
        # print(i, cnt[i])
    # print(xx)
    # return ans
    # print(ans)
    if i - 1 < x // (i + 1):
        return ans
    
    MAX = x // (i + 1)
    MIN = x // (y + 1)
    # print(MAX, MIN)
    xx = 0
    for i in range(MAX, MIN, -1):
        ans += i * (floor(x / i) - ceil(x / (i + 1)) + 1)
        if x % (i + 1) == 0: 
            ans -= i
            # print(i, (floor(x / i) - ceil(x / (i + 1)) ) )
        # else:
        # print(i, (floor(x / i) - ceil(x / (i + 1)) + 1))
    ans += MIN * (y - floor(x / (MIN + 1)) + 1)
    if x % (MIN + 1) == 0:
        ans -= MIN
        
    # j = y
    # while x // (j + 1) == MIN:
        # j -= 1
        # xx += 1

    # print(xx, j)
    # print(MIN, y - j)
    # print((y - j) * MIN)
    # ans += MIN * (y - j)

    return ans

n = int(input())
for i in range(n):
    x, y = input().split()
    x = int(x)
    y = int(y)
    print(func(x, y))
