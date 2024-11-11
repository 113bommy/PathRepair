q = int(input())

def isPossible(a, k, x):
    for i in range(len(a)):
        diff = abs(x - a[i])
        if diff > k:
            if a[i] > x:
                return False, True
            else:
                return False, False
            
    return True, True

def findMax(a, k, l, h):
    res = -1
    if l <= h:
        mid = l + int((h - l)/2)
        temp = isPossible(a, k, mid)
        if temp[0]:
            res = max(mid, findMax(a, k, mid + 1, h))
        elif not temp[0] and temp[1]:
            res = findMax(a, k, mid + 1, h)
        elif not temp[0] and not temp[1]:
            res = findMax(a, k, l, mid - 1)
    return res

for i in range(q):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()
    res = findMax(a, k, 1, 10)
    print(res)