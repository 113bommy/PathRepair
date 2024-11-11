import sys
import math
 
n, k = [int(x) for x in (sys.stdin.readline()).split()]

arr = []
for i in range(51):
    arr.append([0] * 51)

for i in range(n):
    pi, ti = [int(x) for x in (sys.stdin.readline()).split()]
    arr[pi][ti] += 1

c = 0
for i in range(50, 0, -1):
    for j in range(51):
        if(arr[i][j] != 0):
            c += arr[i][j]
            if(k <= c):
                print(arr[i][j])
                exit()


