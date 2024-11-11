# import os

n, k = map(int, input().split())
a = list(map(int, input().split()))


c=0
while a and (a[0] <= k or a[-1] <= k):
    if a[0] <= k:
        a = a[1:]
        c +=1
    if not a:
        break
    if a[-1] <= k:
        a = a[-1:]
        c += 1
print(c)





# 04/01 - 21
# 05/01 - 27
# 06/01 - 28




    