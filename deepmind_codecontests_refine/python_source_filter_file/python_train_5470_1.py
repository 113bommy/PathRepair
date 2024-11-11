from math import gcd
n = int(input())
arr = list(map(int, input().split(' ')))
count = 0
ans = []
for i in range(len(arr)-1):
    ans += [arr[i]]
    if gcd(arr[i], arr[i+1]) > 1:
        ans += [1]
        count += 1
ans += [arr[-1]]
print(count)
print(*arr)