import math

n, k = (int(i) for i in input().strip().split())
arr = [int(x) for x in input().split()]
count = [None]*k
for i in range(k):
    a = i
    temp = arr.copy()
    while a < len(temp):
        temp[a] = 0
        a += k
    count[i] = int(math.fabs(temp.count(1) - temp.count(-1)))
print(max(count))
