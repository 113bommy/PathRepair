for _ in range(int(input())):
    s = list(input())
    low, up, dig = 0, 0, 0
    for c in s:
        if c.isupper():
            up += 1
        elif c.islower():
            low += 1
        else:
            dig += 1
            
    if up > 0 and low > 0 and dig > 0:
        print("".join(s))
    else:
        if len(s) == low:
            s[0] = "1"
            s[1] = "A"
        elif len(s) == up:
            s[0] = "1"
            s[1] = "a"
        elif len(s) == dig:
            s[0] = "a"
            s[1] = "A"
        elif low == 0:
            if s[0].isupper and up > 1:
                s[0] = "a"
            elif s[0].isdigit() and dig > 1:
                s[0] = "a"
            else:
                s[1] = "a"
        elif up == 0:
            if s[0].islower and low > 1:
                s[0] = "A"
            elif s[0].isdigit() and dig > 1:
                s[0] = "A"
            else:
                s[1] = "A"
        else: #dig == 0
            if s[0].isupper and up > 1:
                s[0] = "1"
            elif s[0].islower() and lower > 1:
                s[0] = "1"
            else:
                s[1] = "1"
        print("".join(s))