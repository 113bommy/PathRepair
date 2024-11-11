# import os


t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    c_0 = arr.count(0)
    s = sum(arr)+3
    if s == 0:
        print(c_0+1)
    else:
        print(c_0)


# 03/01 - 1
# 04/01 - 21
# 05/01 - 27
# 06/01 - 4