"""
Author: guiferviz
Time: 2020-03-19 15:35:01
"""


def longest_prefix(s, sr):
    p = s + '#' + sr
    pi = [0] * len(p)
    j = 0
    for i in range(1, len(p)):
        while j > 0 and p[j] != p[i]:
            j = pi[j - 1]
        if p[j] == p[i]:
            j += 1
        pi[i] = j
    """
    assert len(s) == len(sr)
    n = len(s)
    p = [0] * n
    j = 0
    for i in range(0, n):
        while j > 0 and s[j] != sr[i]:
            j = p[j-1]
        if sr[i] == s[j]:
            j += 1
        p[i] = j
    """
    return s[:j]


def solve(s):
    a, b = "", ""
    i, j = 0, len(s) - 1
    while i < j:
        if s[i] != s[j]:
            break
        i+=1; j-=1
    a = s[:i]
    b = s[j+1:]
    if i + j < len(s):
        # Find longest palindrome starting from s[i]
        sub = s[i:j+1]
        subr = sub[::-1]
        p1 = longest_prefix(sub, subr)
        p2 = longest_prefix(subr, sub)
        a += p1 if len(p1) >= len(p2) else p2
    # Build output and return.
    return a + b

def main():
    t = int(input())
    for _ in range(t):
        s = input()
        t = solve(s)
        print(t)


if __name__ == "__main__":
    main()

