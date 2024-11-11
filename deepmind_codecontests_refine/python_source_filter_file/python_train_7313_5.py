import os

import sys

debug = True

if debug and os.path.exists("input.in"):
    input = open("input.in", "r").readline
else:
    debug = False
    input = sys.stdin.readline


def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return s[:len(s) - 1]  # Remove line char from end


def invr():
    return (map(int, input().split()))


test_count = int(input())

for t in range(test_count):
    if debug:
        print("Test Case #", t + 1)
    # Start code here
    n, k = invr()
    totals = {}
    min_ans = -1
    for i in range(10):
        sum_x = 0
        digit_sum = -1
        last_digit = -1
        for j in range(0, k + 1):
            if i + j < 10:
                sum_x += i + j
            else:
                sum_x += (i + j) // 10 + ((i + j) % 10)
        if sum_x <= n and (n - sum_x) % (k + 1) == 0:
            digit_sum = (n - sum_x) // (k + 1)
            last_digit = i
            ans = ""
            if last_digit + k > 9 and digit_sum >= 9:
                ans += "8"
                digit_sum -= 8
            while digit_sum > 9:
                ans += "9"
                digit_sum -= 9
            if digit_sum > 0:
                ans = str(digit_sum) + ans

            ans += str(last_digit)
            if min_ans == -1 or int(ans) < min_ans:
                min_ans = int(ans)
    print(min_ans)
