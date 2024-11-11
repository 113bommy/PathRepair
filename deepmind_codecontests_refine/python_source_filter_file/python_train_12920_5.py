t = int(input())
result = []
low = "abcdefghijklmnopqrstuvwxyz"
upp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
number = "123456789"

for i in range(t):
    is_lower = 0
    is_upper = 0
    is_number = 0

    s = input()
    for i in s:
        if i in low:
            is_lower += 1
        elif i in number:
            is_number += 1
        elif i in upp:
            is_upper += 1
    if is_lower > 0 and is_upper > 0 and is_number > 0:
        print(s)
    else:
        if is_lower == 0 and is_upper == 0:
            print("aA" +s[2:])
        elif is_lower == 0 and is_number == 0:
            print("a1" + s[2:])
        elif is_upper == 0 and is_number == 0:
            print("A1" + s[2:])
        elif is_lower == 0:
            if is_upper > 1:
                for i in range(len(s)):
                    if s[i] in upp:
                        print(s[:i]+"a"+s[i+1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in number:
                        print(s[:i]+"a"+s[i+1:])
                        break
        elif is_upper == 0:
            if is_lower > 1:
                for i in range(len(s)):
                    if s[i] in low:
                        print(s[:i]+"A"+s[i+1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in number:
                        print(s[:i]+"A"+s[i+1:])
                        break
        elif is_number == 0:
            if is_lower > 1:
                for i in range(len(s)):
                    if s[i] in low:
                        print(s[:i] + "1" + s[i + 1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in upp:
                        print(s[:i] + "1" + s[i + 1:])
                        break
