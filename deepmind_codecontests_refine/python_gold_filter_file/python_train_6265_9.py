def solve():
    n = input()
    s = input()
    if int(n) % 2 == 1:
        return print('NO')
    open_bracket = 0
    unopened_bracket = 0
    for char in s:
        if char == '(':
            open_bracket += 1
        elif open_bracket > 0:
            open_bracket -= 1
        elif unopened_bracket < 1:
            unopened_bracket += 1
        else:
            return print('NO')
    open_bracket -= unopened_bracket
    print('YES' if open_bracket == 0 else 'NO')


solve()
