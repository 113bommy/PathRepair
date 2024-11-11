import random

n=int(input())
array=list(map(int,input().split()))
for i in range(1,n):
    if i % 2 == 0:
       array.remove(max(array))
    else:
        array.remove(min(array))
print(array[0])


