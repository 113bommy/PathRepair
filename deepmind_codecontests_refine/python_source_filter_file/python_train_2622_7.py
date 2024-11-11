import sys


def input():
    return sys.stdin.readline().rstrip()


def slv():
    s = list(input()[::-1])
    s = list(map(int, s))
    ans = 0
    n = len(s)
    RPOS = [n]*(n)
    for i in range(n):
        if s[i] == 1:
            RPOS[i] = i
    for i in range(n - 1, -1, -1):
        if i + 1 < n:
            RPOS[i] = min(RPOS[i], RPOS[i + 1])
    for l in range(n):
        left_comp, right_comp = 0, 0
        for r in range(l, min(l + 20, n)):
            left_comp += pow(2, r - l) * s[r]
            right_comp += 1
            if left_comp == right_comp:
                ans += 1
        m = min(l + 20,n) - 1
        if right_comp <= left_comp < RPOS[m] - l:
            ans += 1
    print(ans)



    return

 
def main():
    t = int(input())
    for i in range(t):
        slv()
    return 

def main():
    t = int(input())
    for i in range(t):
        slv()
    return


if __name__ == "__main__":
    main()
