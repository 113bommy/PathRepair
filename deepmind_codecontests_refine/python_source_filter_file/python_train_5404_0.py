def expr():
    global cur
    while cur < len(S):
        cur += 1 # '('
        if clause():
            return 1
        cur += 1 # ')'
    return 0

def clause():
    R = []
    global cur
    R.append(literal())
    cur += 1 # '&'
    R.append(literal())
    cur += 1 # '&'
    R.append(literal())
    return check(R)

def literal():
    global cur
    if S[cur] == '~':
        r = S[cur:cur+2]
        cur += 2 # '~a'
    else:
        r = S[cur]
        cur += 1 # 'a'
    return r

def check(R):
    for l0 in R:
        if len(l0) == 1:
            for l1 in R:
                if len(l1) == 2 and l1[1] == l0:
                    return 0
    return 1


ans = []
while 1:
    S = input()
    if S == '#':
        break
    cur = 0
    ans.append('yes' if expr() else 'no')
print(*ans, sep='\n')

