

def solve(s):
    if 'L' not in s:
        return 1
    if 'R' not in s:
        return len(s) + 1
    ans = 0
    r = []
    for i in range(len(s)):
        if s[i] == 'R':
            r.append(i)
    md = 0
    for i in range(len(r)-1):
        md = max(r[i]+1 - r[i], md)
    return max(r[0]+1, len(s)-r[-1], md)


def main():
    t = int(input())
    for _ in range(t):
        s = input()
        print(solve(s))


main()