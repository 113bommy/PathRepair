from itertools import chain
from sys import stdin, stdout

def main():
    input = stdin.readline
    for _ in range(int(input())):
        n, k = map(int, input().split())
        ans = [k, k, k, 1, 1]
        fin_ans = k
        inp = tuple(((ord('r') + i - ord(c)) % 3 for i, c in enumerate(input().lower())))
        for inp1, inp2 in zip(inp, chain((4,) * k, inp)):
            ans[inp2] += 1
            ans[inp1] -= 1
            fin_ans = min(fin_ans, ans[inp1])
        stdout.write(f'{fin_ans}\n')


main()
