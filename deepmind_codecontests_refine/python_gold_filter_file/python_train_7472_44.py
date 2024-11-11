def encode(s):
    val = 0
    min_val = 0
    for c in s:
        if c == '(':
            val += 1
        else:
            val -= 1
            min_val = min(min_val, val)
    return [min_val, val]

def check(s):
    h = 0
    for p in s:
        b = h + p[0]
        if b < 0:
            return False
        h += p[1]
    return True


n = int(input())
ls = []
rs = []
l_total = 0
r_total = 0
for _ in range(n):
    si = encode(input())
    if si[1] > 0:
        ls.append(si)
        l_total += si[1]
    else:
        si[0] -= si[1]
        si[1] *= -1
        rs.append(si)
        r_total += si[1]
list.sort(ls, reverse=True)
list.sort(rs, reverse=True)
if check(ls) and check(rs) and l_total == r_total:
    print("Yes")
else:
    print("No")
