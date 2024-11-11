def is_correct(s):
    cumsum = 0
    for k in s:
        if k == "(":
            cumsum += 1
        elif k == ")":
            cumsum -= 1

        if cumsum == -2:
            return False

    return cumsum == 0

if is_correct(input()):
    print("Yes")
else:
    print("No")

