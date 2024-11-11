n = int(input())
L = [int(i) for i in input().split()]
su = 0
l = n
for i in range(n - 1, 0, -1):
    nl = max(i - L[i], 0)
    if l > nl:
        if i < l:
            su += i - nl
        else:
            su += l - nl
        l = nl
    if l <= 0:
        break
print(n - su)