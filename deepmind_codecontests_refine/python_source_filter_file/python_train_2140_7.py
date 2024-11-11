import bisect
import sys

EPS = sys.float_info.epsilon

LENGTH = 10
matrix = [[] for i in range(LENGTH)]
array = [0] * LENGTH


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    b = [10 ** 12]
    b.extend(list(map(int, sys.stdin.readline().split())))
    b.append(10 ** 12)
    answer = 0
    for val in a:
        index_l= bisect.bisect_left(b, val)
        index_r = bisect.bisect_left(b, val)
        answer1 = min(abs(val - b[index_l - 1]), abs(b[index_l] - val))
        answer2 = min(abs(val - b[index_r - 1]), abs(b[index_r] - val))
        answer = max(answer, min(answer1, answer2))
    print(answer)
