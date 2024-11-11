import bisect
import sys

EPS = sys.float_info.epsilon

LENGTH = 10
matrix = [[] for i in range(LENGTH)]
array = [0] * LENGTH


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    answer = 0
    for val in a:
        index_l = bisect.bisect_left(b, val)
        index_r = bisect.bisect_left(b, val)
        ans1 = 10000000000000
        ans2 = 10000000000000
        if index_l > 0:
            ans1 = abs(val - b[index_l - 1])
        if index_l < len(b) - 1:
            ans2 = abs(b[index_l] - val)
        answer1 = min(ans1, ans2)
        ans1 = 10000000000000
        ans2 = 10000000000000
        if index_r > 0:
            ans1 = abs(val - b[index_r - 1])
        if index_r < len(b) - 1:
            ans2 = abs(b[index_r] - val)
        answer2 = min(ans1, ans2)
        answer = max(answer, min(answer1, answer2))
    print(answer)
