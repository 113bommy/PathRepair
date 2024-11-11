import sys
import math

on = None
ans = 100
x = -1

def is_square(x):
    decimal = math.sqrt(x) - math.floor(math.sqrt(x))
    return decimal == 0

def check_number():
    digits = [x[i] for i in range(len(x)) if on[i]]

    if digits and int(digits[0]):
        num = 0
        for digit in digits:
            num = 10 * num + int(digit)

        if is_square(num):
            global ans
            ans = min(ans, len(x) - len(digits))

def recurse(idx):
    if idx == len(on):
        check_number()
        return

    on[idx] = True
    recurse(idx + 1)

    on[idx] = False
    recurse(idx + 1)

input_ = sys.stdin.read().split()
x = input_[0]

on = [False for _ in range(len(x))]
recurse(0)

print(-1 if ans == 100 else ans)
