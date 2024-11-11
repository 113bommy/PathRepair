def weight(side):
    res = 0
    pos = 1
    for char in side:
        if char != '=':
            res += int(char)*pos
        pos += 1
    return res


if __name__ == '__main__':
    lefts, rights = input().split('^')
    left_weight = weight(lefts[::-1])
    right_weight = weight(rights)
    if left_weight > right_weight:
        print("left")
    elif right_weight > left_weight:
        print("right")
    else:
        print("balance")