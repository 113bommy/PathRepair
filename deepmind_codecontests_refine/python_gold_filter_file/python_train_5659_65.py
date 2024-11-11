s = input()
res = ""
loc = ""
i = 0
while i < len(s):
    if i <= (len(s) - 3) and s[i] == 'W' and s[i+1] == 'U' and s[i + 2] == 'B':
        if res == "":
            res = loc
        elif loc != "":
            res += " " + loc
        i += 2
        loc = ""
    else:
        loc += s[i]
    i += 1
res += " " + loc
print(res)
