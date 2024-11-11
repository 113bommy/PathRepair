left_border_inclusive = float("-inf")
right_border_inclusive = float("inf")

inverse_signs = {
    ">": "<=",
    "<=": ">",
    ">=": "<",
    "<": ">="
}

NUMBERS = int(input())
EXTRA_FINISH = False

sign, value = None, None
for _ in range(NUMBERS):
    sign, value, answer = input().split(' ')
    value = int(value)
    if answer == "N":
        sign = inverse_signs[sign]

    if sign == ">":
        if value >= right_border_inclusive:
            EXTRA_FINISH = True
            break
        left_border_inclusive = max(left_border_inclusive, value + 1)
    elif sign == ">=":
        if value > right_border_inclusive:
            EXTRA_FINISH = True
            break
        left_border_inclusive = max(left_border_inclusive, value)
    elif sign == "<":
        if value <= left_border_inclusive:
            EXTRA_FINISH = True
            break
        right_border_inclusive = max(right_border_inclusive, value-1)
    elif sign == "<=":
        if value < left_border_inclusive:
            EXTRA_FINISH = True
            break
        right_border_inclusive = max(right_border_inclusive, value)

if not EXTRA_FINISH:
    if left_border_inclusive == float("-inf"):
        print(right_border_inclusive)
    else:
        print(left_border_inclusive)
else:
    print("Impossible")