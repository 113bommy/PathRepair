from collections import deque

def calcwidth(cks):
    if len(cks) == 1: return cks[0]*2
    width = cks[0] + cks[-1]
    for ck1,ck2 in zip(cks[:-1],cks[1:]):
        width += ((ck1+ck2)**2-(ck1-ck2)**2)**0.5
    return width

while True:
    try: W, *rs = list(map(float,input().split()))
    except: break
    rs = deque(sorted(rs))
    dp = [float('inf')]*len(rs)
    cs = deque([rs.popleft()])

    last_pick_small = -1
    # if -1: last pick up is smallest, if 0: last pick up is biggest
    while rs:
        if last_pick_small: nxt = rs.pop()
        else: nxt = rs.popleft()
        if abs(nxt-cs[0]) > abs(nxt-cs[-1]): cs.appendleft(nxt)
        else: cs.append(nxt)
        last_pick_small = -1-last_pick_small
    ret = calcwidth(list(cs))
    if ret < W: print('OK')
    else: print('NA')


