from collections import Counter

def solve(n, s):
    c = Counter(s)
    if len(s) == 1: return "Yes"
    for i in c.values():
        if i > 1: 
            return "Yes"
    return "No"


def main():
    n = int(input())
    s = input()
    print(solve(n, s))


main()
