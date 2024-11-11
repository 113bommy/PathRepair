"""
    author - Sayan Bose
    date - 26.01.2020
    Brooklyn 99 is love!
"""

n, k = map(int, input().split())
li = list(map(int, input().split()))
for i in range(2*n+1):
    if not k:
        break
    if (i+1) & 1 == 0:
        if i != 2*n:
            if li[i] - 1 < li[i-1] or li[i] - 1 < li[i+1]:
                continue
            else:
                li[i] -= 1
                k -= 1
        else:
            if k:
                li[i] -= 1
print(*li)
