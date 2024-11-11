
n = int(input())

import math

key = n
arr = []
for i in range(1,math.ceil(pow(n,0.5))+1):
    key = key - math.floor(pow(n,0.5))
    for j in range(1,math.floor(pow(n,0.5))+1):
        if key+j>0:
            arr.append(key+j)

#print(arr)
for i in range(1,min(arr)):
    arr.append(i)


print(arr)
