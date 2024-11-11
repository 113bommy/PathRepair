def bs(n) :
    start = 0
    end = len(arr) - 1
    ret = -1
    while(start <= end) :
        mid = (start + end) >> 1
        if(arr[mid] <= n) :
            ret = arr[mid]
            start = mid + 1
        else :
            end = mid - 1
    return ret

def solve(n) : 
    val = bs(n)
    if(val == -1) : return 0
    return 1 + solve(n - val)

arr = [2]
for i in range(1,1000000) :
    arr.append(2 * (i + 1) + i)
    arr[i] += arr[i - 1]

for _ in range(int(input())) : print(solve(int(input())))