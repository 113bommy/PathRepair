from string import ascii_lowercase as l
n,k = map(int, input().split())
arr = sorted(list(map(lambda a: l.index(a)+1, input())))

def haha(n,k,arr):
    if k == 1:
        return arr[0]
    
    sumi = 0
    cur = -1

    for num in range(0,n-1):
        if k == 0:
            break 
        if arr[num] - cur >= 2:
            sumi += arr[num]
            k -= 1
            cur = arr[num]
        

    if k == 0:
        return sumi
    return -1

print(haha(n,k,arr))
