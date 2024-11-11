import math
n = int(input())
a = list(map(int, input().split()))
l = 0
r = len(a)-1
ans = []
last = -math.inf
while True:
    if l > r:
        break
    if a[l] <= a[r] and a[l] > last:
        ans.append('L')
        last = a[l]
        l += 1
    elif a[r] > last:
        ans.append('R')
        last = a[r]
        r -= 1
    elif a[l] > last:
        ans.append('L')
        last = a[l]
        l += 1
    else:
        break
print(len(ans))
print(''.join(ans))