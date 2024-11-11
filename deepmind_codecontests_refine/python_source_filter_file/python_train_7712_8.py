n = int(input())
arr = list(map(int, input().split()))
s1, s2 = 0, 0
i, j = 0, n - 1
res = 0
while i < j:
    s1 += arr[i]
    while s2 < s1 and j > i:
        s2 += arr[j]
        j -= 1
    if s1 == s2:
        res = s1
    i += 1
print(res)
