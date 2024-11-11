"""
ai = ai + aj
aj = aj - ai

1 ai + aj, aj
2 ai + aj, -ai
1 aj, -ai
2 aj, -ai-aj
1 -ai, -ai-aj
2 -ai, -aj
"""


def test():
    n = int(input())
    arr = list(map(int, input().split()))
    opts = int(n / 2 * 6)
    print(opts)
    for i in range(1, n + 1, 2):
        for _ in range(3):
            print(f'1 {i} {i + 1}')
            print(f'2 {i} {i + 1}')


if __name__ == "__main__":
    num_cases = int(input())
    for _ in range(0, num_cases):
        test()
