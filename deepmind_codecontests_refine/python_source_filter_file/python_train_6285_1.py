def check_bracket(seq: str) -> int:
    opened, finished = int(), int()
    for bracket in seq:
        if bracket == '(':
            opened += 1
        elif bracket == ')' and opened:
            opened -= 1
            finished += 2
    return finished


print(check_bracket('((()())'))