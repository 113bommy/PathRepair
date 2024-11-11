def debin(s):
    ret = 0
    mn = 1
    for i in range(len(s)-1,-1,-1):
        ret += int(s[i]) * mn
        mn *=2
    return ret
st = set()
def ch(x,y,deep):
    if x in st:
        return 0
    st.add(x)
    if x == y:
        return 1
    if deep == 15:
        return 0
    s = bin(x)[2:]
    if ch(debin(s[::-1]),y,deep+1) or ch(debin('1' + s[::-1]),y,deep+1):
        return 1
    return 0

x, y = map(int, input().split())
if ch(x,y,0):
    print("YES")
else:
    print("NO")
