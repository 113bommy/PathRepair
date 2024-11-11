from collections import Counter
from sys import stdin

def score_stirng(data, n):
    most_common = [Counter(s).most_common(1)[0][1] for s in data]
    score = [min(n == 1 and score == len(s) and len(s) - 1 or len(s), score+n) for s, score in zip(data, most_common)]
    return score

if __name__ == '__main__':
    n, first, second, third = [stdin.readline(), stdin.readline(), stdin.readline(), stdin.readline()]
    s = score_stirng([first, second, third], int(n))
    if s[0] > s[1] and s[0] > s[2]:
        print('Kuro')
    elif s[1] > s[0] and s[1] > s[2]:
        print('Shiro')
    elif s[2] > s[0] and s[2] > s[1]:
        print('Katie')
    else:
        print('Draw')