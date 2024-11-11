import sys
input = sys.stdin.readline
def solve():
    n = int( input())
    P = list( map( int, input().split()))
    ret = 2
    ans = [P[0], P[1]]
    now = P[1]
    up = False
    if P[0] < P[1]:
        up = True
    for p in P[2:]:
        if up:
            if now < p:
                ans[-1] = p
                pass
            else:
                up = False
                ret += 1
                ans.append(p)
        else:
            if now > p:
                ans[-1] = p
                pass
            else:
                up = True
                ret += 1
                ans.append(p)
        now = p

    return "\n".join( [str(ret), " ".join( map( str, ans))])
def main():
    t = int( input())
    ANS = []
    for _ in range(t):
        print( solve())

if __name__ == '__main__':
    main()
