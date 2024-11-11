from sys import stdin


def inp():
    return stdin.buffer.readline().rstrip().decode("utf8")


def itg():
    return int(stdin.buffer.readline())


def mpint():
    return map(int, stdin.buffer.readline().split())


# ############################## import
def partial(s):
    g, pi = 0, [0] * len(s)
    for i in range(1, len(s)):
        while g and (s[g] != s[i]):
            g = pi[g - 1]
        pi[i] = g = g + (s[g] == s[i])

    return pi


def match(s, pat):
    pi = partial(pat)

    g, idx = 0, []
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            idx.append(i + 1 - g)
            g = pi[g - 1]

    return idx


# ############################## main
import re
KEY_WORD = 'abacaba'
REG = re.compile(r'[a?][b?][a?][c?][a?][b?][a?]')


def main():
    n = itg()
    s = inp()
    occurrence = len(match(s, KEY_WORD))
    if occurrence >= 2:
        return "No"
    elif occurrence == 1:
        return "Yes\n" + s.replace('?', 'x')
    for i in range(n-len(KEY_WORD)+1):
        if not REG.match(s[i: i+len(KEY_WORD)]):
            continue
        check = s[: i] + KEY_WORD + s[i+7:]
        if len(match(check, KEY_WORD)) == 1:
            ans = list(s)
            ans[i:i+7] = list(KEY_WORD)
            return "Yes\n" + ''.join(ans).replace('?', 'x')

    return "No"


for case in range(itg()):
    print(main())

# Please check!
