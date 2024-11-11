def lower_bound(array, x, low =0, high = None):
    if len(array) == 0:
        return 0
    if high == None:
        high = len(array)
    while(low < high):
        mid = (low + high)//2
        if x < array[mid]:
            high = mid
        else:
            low = mid + 1
    return low

n = int(input())
ass = list(map(int, input().split()))
bss = list(map(int, input().split()))
for i in range(n):
    ass[i] -= bss[i]
ass = sorted(ass)
negs = lower_bound(ass, -0.5)
zeros = ass.count(0)
ans = ((n-negs-zeros)*(n-negs-1-zeros))//2
for i in ass:
    if i >= 0:
        break
    req = abs(i) + 1
    k = lower_bound(ass, req)
    this = n - k + 1
    if ass[k-1] != req:
        this -= 1
    ans += this
print(ans + zeros*(n-negs-zeros))