import sys
import os.path

INF = int(1e9)

if __name__ == '__main__':
    if os.path.isfile("in.txt"):
        sys.stdin = open("in.txt", "r", encoding="utf-8")
    n = int(input())
    arr = list(map(int, input().split()))
    ans = -INF
    for _max in range(0, 31):
        _sum = 0
        max_sum = -INF
        for num in arr:
            val = num if num <= _max else -INF
            _sum += val
            max_sum = max(max_sum, _sum)
            _sum = max(_sum, 0)
        ans = max(ans, max_sum - _max)
    print(ans)
