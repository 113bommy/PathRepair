def cnt(s):
    ret = 0
    for ch in s:
        ret += bool(ch is '1')
    return ret
a = input()
b = input()
acount , bcount = [cnt(a), cnt(b)]
if len(a) is not len(b):
    print("NO")
else:
    if acount is bcount:
        print("YES")
    elif acount > bcount and bcount is not 0:
        print("YES")
    elif acount < bcount and acount is not 0:
        print("YES")
    else:
        print("NO")