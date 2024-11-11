s = input()

i, heavy, count = 0, 0, 0
while i < len(s) - 5:
    if (s[i] == "h" and s[i+1] == "e" and s[i+2] == "a" and
        s[i+3] == "v" and s[i+4] == "y"):
        heavy += 1
        i += 5
    elif (s[i] == "m" and s[i+1] == "e" and s[i+2] == "t" and
        s[i+3] == "a" and s[i+4] == "l"):
        count += heavy
        i += 5
    else:
        i += 1

print(count)