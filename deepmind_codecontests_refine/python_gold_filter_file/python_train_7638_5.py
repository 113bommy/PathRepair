from sys import stdin
import math
 
n,m,d= list(map(int, stdin.readline().rstrip().split(' ')))
arr = []

for r in range(n):
    for num in list(map(int, stdin.readline().rstrip().split(' '))):
        arr.append(num)
        
arr.sort()

diff = None
for num in arr:
    if diff is None:
        diff = num % d
    elif diff == num % d:
        continue
    else:
        print(-1)
        exit()

med = arr[len(arr) // 2]
print(sum(abs(num - med) for num in arr) // d)