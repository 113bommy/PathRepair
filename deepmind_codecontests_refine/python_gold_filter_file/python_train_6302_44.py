import math

n = int(input())

def digits_length(num):
    arr = [0, 10, 100, 1000]
    result = 1
    for i, a in enumerate(arr):
        if num >= a:
            result = i + 1
        else:
            break
    return result

def digit_on_position(num, pos):
    if pos > 0:
        num = math.floor(num / (10 ** pos))

    return num % 10

cur = 0
dig = 0
while cur < n:
    dig += 1
    cur += digits_length(dig)

print(digit_on_position(dig, cur - n))
