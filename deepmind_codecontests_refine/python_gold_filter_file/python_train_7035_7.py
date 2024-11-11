
p = input()
t = input()
arr = [int(i)-1 for i in input().split(' ')]

def check(mid) :
    l = list(p)
    for i in range(mid+1) :
        l[arr[i]] = ' '
    
    found = 0
    i = 0
    while found < len(t) and i < len(arr) :
        if l[i] is t[found] :
            found += 1
        i += 1

    return found == len(t)


l , r  = -1 , len(arr)-1

while l < r :
    mid = (l + r + 1)//2
    if check(mid) :
        l = mid
    else :
        r = mid - 1

print(l+1)
