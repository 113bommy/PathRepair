# n = int(input())
# w, h = map(int, input().split())
# to_zero_based = lambda x: int(x) - 1
from collections import defaultdict

def main():
    n, p, q = map(int, input().split())
    s = input()

    exsited = set()
    for i in range(0, n, p):
        rem = (n - i) % q
        if rem == 0:
            front = s[:i]
            back = s[i:]
            ss = [front[j:j+p] for j in range(0, i, p)] + [back[j:j+q] for j in range(0, n - i, q)]
            print(len(ss))
            print('\n'.join(ss))
            return
        if rem in exsited:
            break
        exsited.add(rem)

    print(-1)

main()
