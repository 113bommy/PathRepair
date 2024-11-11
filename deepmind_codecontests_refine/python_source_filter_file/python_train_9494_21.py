import sys
from collections import Counter
from math import ceil


def possible_wins(a,b,c, seq):
    co = Counter(seq)
    wins = 0
    wins += min(co['R'], b)
    wins += min(co['P'], c)
    wins += min(co['S'], a)

    return wins

def winning_seq(a,b,c, seq):
    winning_seq = [None]*(a+b+c)
    for i,move in enumerate(seq):
        if move == "R" and b > 0:
            b -= 1
            winning_seq[i] = "P"
        elif move == "S" and c > 0:
            c -= 1
            winning_seq[i] = "R"
        elif move == "P" and a > 0:
            a -= 1
            winning_seq[i] = "S"
    for i,e in enumerate(winning_seq):
        if e is None:
            if a > 0:
                a -= 1
                winning_seq[i] = "R"
            elif b > 0:
                b -= 1
                winning_seq[i] = "S"
            elif c > 0:
                c -= 1
                winning_seq[i] = "P"

    return "".join(winning_seq)

def main():
    t = int(sys.stdin.readline())
    n,a,b,c, seq = [None]*t,[None]*t,[None]*t,[None]*t, [None]*t
    for i in range(t):
        n[i] = int(sys.stdin.readline())
        a[i],b[i],c[i] = map(int, sys.stdin.readline().split())
        seq[i] = sys.stdin.readline().strip()
    for i in range(t):
        if possible_wins(a[i], b[i], c[i], seq[i]) >= ceil(n[i]/2):
            print("YES")
            print(winning_seq(a[i], b[i], c[i], seq[i]))
        else:
            print("NO")


if __name__ == "__main__":
    main()
