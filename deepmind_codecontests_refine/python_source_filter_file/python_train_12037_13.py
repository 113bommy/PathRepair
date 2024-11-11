from bisect import bisect_left
n,k = list(map(int, input().split()))
lst = sorted(list(map(int, input().split())))
count = 0
 
i = bisect_left(lst,k)
# print('i: ',i)
if k in lst:
    count += 1
 
last = 0
for j in range(i):
    count += max(0, lst[j] - last -1)
    last = lst[j]
count += max(0, k-last-1)
print(count)