n, l = [int(a) for a in input().split()]
list1 = [int(a) for a in input().split()]
list1.sort()
max1 = -1
for x in range(n-1):
    curr = list1[x+1]-list1[x]
    if curr > max1:
        max1 = curr
max1 = max1/2
if list1[0] > max1:
    max1 = list1[0]
if l-list1[-1] > max1:
    max1 = list1[0]
print(max1)
