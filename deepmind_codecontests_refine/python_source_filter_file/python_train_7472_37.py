def kton(S):
    r = 0
    m = 0
    for s in S:
        r += 1 if s == '(' else -1
        m = min(m, r)
    return r, m
        
def main():
    N = int(input())
    RM = [kton(input()) for _ in range(N)]
    pos = 0
    negp = []
    negn = []
    posn = []
    for r, m in RM:
        if m < 0:
            if r >= 0:
                negp.append((-m, r))
            else:
                negn.append((-(-r+m), -r, m))
        else:
            pos += r

    negp.sort()
    for m, r in negp:
        if pos - m < 0:
            return False
        pos += r
    negn.sort()
    for _, r, m in negn:
        if pos + m < 0:
            return False
        pos -= r
    return pos == 0

print('Yes' if main() else 'No')
