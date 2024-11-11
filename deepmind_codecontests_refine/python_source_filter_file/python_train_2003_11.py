from math import log2, ceil


T = int(input())



for test in range(T):
    N = int(input())
    data = list(map(int, input().split()))

    max_t = 0
    for i in range(1, N):
        diff = data[i-1] - data[i]
        t = 0
        if diff > 0:
            t = ceil(log2(diff+1))
            data[i] += 2**(t-1)
            if t > max_t:
                max_t = t
    print(max_t)
    
