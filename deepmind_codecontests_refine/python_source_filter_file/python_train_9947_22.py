def get(val):
    global t, s
    if (val == 0):
        return t
    val += 2
    if (val % 2 == 1):
        return t + (val // 2) * s + 1
    else:
        return t + (val // 2) * s


t, s, x = list(map(int, input().split()))
le = 0
ri = 10 ** 9 + 500

while (ri - le > 1):
    mid = (le + ri) // 2
    val = get(mid)
    if (val > x):
        ri = mid
    else:
        le = mid
if (get(le) == x):
    print("YES")
else:
    print("NO")