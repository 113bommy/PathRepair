import sys
from math import sqrt

def solve():
    s = input() # Oleg's letters
    t = input() # Igor's letters
    n = len(s)

    s = sorted(s)[:(n + 1) // 2]
    t = sorted(t, reverse=True)[:n // 2]

    '''
    print(s)
    print(t)
    '''

    ans = [None] * n
    ansl = 0
    ansr = n - 1

    olgl = 0
    olgr = len(s) - 1
    igol = 0
    igor = len(t) - 1

    for i in range(n):
        if i % 2 == 0:
            if igol > igor or s[olgl] <= t[igol]:
                ans[ansl] = s[olgl]
                ansl += 1
                olgl += 1
            else:
                ans[ansr] = s[olgr]
                ansr -= 1
                olgr -= 1
            pass
        else:
            if olgl > olgr or t[igol] >= s[olgl]:
                ans[ansl] = t[igol]
                ansl += 1
                igol += 1
            else:
                ans[ansr] = t[igor]
                ansr -= 1
                igor -= 1
            pass

        # print(ans)

    ans = ''.join(ans)

    print(ans)

if __name__ == '__main__':
    solve()