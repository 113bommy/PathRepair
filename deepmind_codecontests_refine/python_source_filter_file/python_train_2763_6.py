keys = {'1': (1, 1), '2': (1, 2), '3': (1, 3),
        '4': (2, 1), '5': (2, 2), '6': (2, 3),
        '7': (3, 1), '8': (3, 2), '9': (3, 3),
                     '0': (4, 2)}
num = input()
left = right = up = down = 0
contains_zero = False
contains_seven = False
contains_eight = False
contains_nine = False
for ch in num:
    y, x = keys[ch]

    if ch == '0':
        contains_zero = True
    if ch == '7':
        contains_seven = True
    if ch == '8':
        contains_eight = True
    if ch == '9':
        contains_nine = True

    if left == 0:
        left = x
    elif x < left:
        left = x

    if up == 0:
        up = y
    elif y < up:
        up = y

    if right == 0:
        right = x
    elif x > right:
        right = x

    if down == 0:
        down = y
    elif y > down:
        down = y

if contains_zero:
    if up > 1:
        answer = True
    else:
        answer = False

elif left > 1 or right < 3 or down < 3 or up > 1:
    answer = True
elif contains_eight and not contains_nine and not contains_seven:
    answer = True
else:
    answer = False

if answer:
    print("NO")
else:
    print("YES")





