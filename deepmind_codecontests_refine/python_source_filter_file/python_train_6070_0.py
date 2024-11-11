import sys

def read_ints():
    return [int(i) for i in sys.stdin.readline().strip().split()]

def read_int():
    return int(sys.stdin.readline().strip())

def check_brackets(s, openers, closers):
    opened = 0
    for c in s:
        if c in openers:
            opened += 1
        else:
            if opened <= 0:
                return False
            opened -= 1
    return opened == 0


def can_bracket(s):
    opener = s[0]
    closer = s[-1]
    if opener == closer:
        return False
    other = [c for c in "abc" if c not in [opener, closer]][0]
    nopeners = sum(1 for c in s if c == opener)
    nclosers = sum(1 for c in s if c == closer)
    nother = len(s) - nopeners - nclosers
    if nother != abs(nopeners - nclosers):
        return False
    if nopeners > nclosers:
        return check_brackets(s, [opener], [closer, other])
    else:
        return check_brackets(s, [opener, other], [closer])


t = read_int()
for i in range(t):
    s = sys.stdin.readline().strip()
    if can_bracket(s):
        print("YES")
    else:
        print("NO")
