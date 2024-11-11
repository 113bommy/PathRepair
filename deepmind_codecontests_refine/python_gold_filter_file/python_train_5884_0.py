def get_upper_num(a):
    nd = 0
    t = a
    while t > 0:
        nd += 1
        t //= 2
    val = 0
    for i in range(nd):
        val += (1 << i)
    ret = -1
    pos = nd + 1
    for i in range(nd - 1):
        cur = val - (1 << i)
        if cur >= a and (ret == -1 or ret > cur):
            ret = cur
            pos = i
    if ret == -1:
        ret = 0
        for i in range(nd + 1):
            ret += (1 << i)
        ret -= (1 << (nd - 1))
        pos = nd - 1
        nd += 1
    return ret, pos, nd

def get_lower_num(a):
    nd = 0
    t = a
    while t > 0:
        nd += 1
        t //= 2
    val = 0
    for i in range(nd):
        val += (1 << i)
    ret = -1
    pos = nd + 1
    for i in range(nd - 1):
        cur = val - (1 << i)
        if cur <= a and (ret == -1 or ret < cur):
            ret = cur
            pos = i
    if ret == -1:
        ret = 0
        for i in range(nd - 1):
            ret += (1 << i)
        ret -= 1
        pos = 0
        nd -= 1
    return ret, pos, nd

a, b = map(int, input().split())
ans = 0
left_num, left_pos, left_nd = get_upper_num(a)
right_num, right_pos, right_nd = get_lower_num(b)
# print(get_upper_num(a))
# print(get_lower_num(b))
if a > right_num or b < left_num:
    ans = 0
elif left_nd < right_nd:
    ans = (left_pos + 1) + (right_nd - 1 - right_pos)
    for i in range(left_nd + 1, right_nd):
        ans += max(0, i - 1)
else:
    ans = left_pos - right_pos + 1
print(ans)