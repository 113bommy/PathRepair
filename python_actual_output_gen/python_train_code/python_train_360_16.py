N = int(input())

def cnt(s):
    if int(s) > N:
        return 0
    ret = 1 if all(s.count(c) > 0 for c in '357') else 0
    for c in '357':
        ret += cnt(s+c)
    return ret

pritn(cnt('0'))