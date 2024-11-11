def binsearch(lst, x):
    l = 0
    r = len(lst)-1
    while l < r:
        mid = (l+r) // 2
        if lst[mid] == x:
            return mid
        elif lst[mid] < x:
            l = mid+1
        else:
            r = mid
    return l
def prefix(pref , num):
    prefs = [pref[0]]
    for i in range(1 , num):
        prefs.append(prefs[-1] + pref[i])
    return prefs
n , m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
prefs = prefix(a , n)
for i in range(m):
    ind = binsearch(prefs, b[i])
    if ind == 0:
        flat = b[i]
    else:
        flat = abs(b[i]-prefs[ind-1])
    print(ind + 1, flat)
