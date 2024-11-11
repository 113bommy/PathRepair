n, k = map(int,input().split())
ai = list(map(int,input().split()))
def binsearch(num):
    high = n
    low = 0
    mid = (high + low) // 2
    while high > low:
        if ai[mid] < num:
            low = mid + 1
        elif ai[mid] > num:
            high = mid - 1
        else:
            return mid
        mid = (high + low) // 2
    return -1
ai.sort()
ar = [0]*n
ans = 0
for i in range(n):
    if ar[i]:
        continue
    num = binsearch(ai[i] * k)
    if num != -1:
        ar[num] = 1
        ans += 1
if k == 1:
    ans = 0
print(ans)
