from sys import stdin
def ip(): return [int(i) for i in stdin.readline().split()]
def sp(): return [str(i) for i in stdin.readline().split()]



def solve():
    s = str(input())
    t= str(input())

    sm, ss = int(s[:2]), int(s[3:])
    tm, ts = int(t[:2]), int(t[3:])

    res = int(((ss - ts) + abs(tm - sm) * 60) // 2)
    rs = res % 60
    rm = int(res // 60)
    ls = int((ss+rs) // 60)

    ss = (ss + rs) % 60
    sm = (sm + rm + ls) % 24

    if ss < 10: ss = "0" + str(ss)
    if sm < 10: sm = "0" + str(sm)
    return str(sm) + ":" + str(ss)


print(solve())