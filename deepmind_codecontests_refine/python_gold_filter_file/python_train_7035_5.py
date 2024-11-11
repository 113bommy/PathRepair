s = input()
t = input()
arr = [x - 1 for x in map(int, input().split())]
l = 0
r = len(s) - 1


def check(sa, sb):
    j = 0
    for i in range(len(sb)):
        while j < len(sa) and sa[j] != sb[i]:
            j += 1
        if j == len(sa):
            return False
        j += 1
    return True


while l < r:
    mid = (l + r + 1) >> 1
    d = list(s)
    for i in range(mid):
        d[arr[i]] = ''
    if check("".join(d), t):
        l = mid
    else:
        r = mid - 1
print(l)
