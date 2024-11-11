import math
t = int(input())
for i in range(t):
    n, k = [int(s) for s in input().split()]
    array = [int(s) for s in input().split()]
    if len(array) == 1:
        print(max(abs(array[0]), abs(n - array[0] + 1)))
        continue
    #array.insert(0, 1)
    #array.append(n)
    max_ = -1
    for i in range(1, len(array)):
        if array[i] - array[i - 1] > max_:
            max_ = array[i] - array[i - 1]
    ans = math.ceil(max_ / 2)
    sec = max(abs(array[0]), abs(n - array[-1] + 1))
    #print(ans,sec)
    print(max(sec, ans))