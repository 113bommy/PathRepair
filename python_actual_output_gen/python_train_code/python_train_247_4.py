n, m = [int (x) for x in input().split()]
l1 = [int (x) for x in input().split()]
l2 = [int (x) for x in input().split()]

minl1 = min(l1)
minl2 = min(l2)

def isElementInList(element, arr):
    a = b = False
    for x in range(len(arr)):
        if(element == arr[x]):
            return True
    return False
l1.sort()
res = -1
for x in l1:
    if(isElementInList(x, l2)):
        res = x
        break

if(res != -1):
    print(res)
else:
    if(minl1 > minl2):
        print(str(minl1)+str(minl2))
    else:
        print(str(minl1)+str(minl2))
    