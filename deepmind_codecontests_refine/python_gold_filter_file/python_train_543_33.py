# import numpy as np
t = int(input())
N = 50*10005
ar = [((i*i)-((i-2)*(i-2)))*(i//2) for i in range(1,N,2)]
# print(ar)
for i in range(1,len(ar)):
    ar[i] = ar[i-1]+ ar[i]
# print(ar)
for i in range(t):
    n = int(input())
    print(ar[n//2])
    