y = int(input())

def is_leap(y):
    return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

def days(y):
    return 365 if not is_leap(y) else 366

shift = days(y) % 7
for ny in range(y + 1, 100000 + 1):
    if is_leap(ny) == is_leap(y) and shift == 0:
        print(ny)
        break
    else:
        shift = (shift + days(ny)) % 7
