from collections import deque

s = deque()
n = input()

def do(s, n):
    flag = False
    for b in n:
        if b=='(':
            s.append(b)
        else:
            if len(s) <= 0:
                if not flag:
                    flag = True
                else:
                    return False
            else:
                s.pop()
    if (len(s)==1 and flag) or (len(s)==0 and not flag) :
        return True
    return False
if do(s,n):
    print('Yes')
else:
    print('No')