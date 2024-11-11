v = input()
while "  " in v: v = v.replace("  ", " ")
i = -1
ln = len(v)
acc = ""
def next():
    global i
    i += 1
    if i >= ln:
        return None
    return v[i]
while True:
    c = next()
    if c == None: break
    if c in "0123456789":
        if len(acc) > 0 and acc[-1] == ",":
            acc += " "
        acc += c
    if c == " ":
        if len(acc) > 0 and acc[-1] != " ":
            acc += c
    if c == ".":
        if len(acc) > 0 and acc[-1] != " ":
            acc += " "
        next(); next();
        acc += "..."
    if c == ",":
        if len(acc) > 1 and acc[-1] == " " and acc[-2] != ",":
            acc = acc[:-1] + ","
        else:
            if len(acc) > 0 and acc[-1] == ",":
                acc += " "
            acc += ","

print(acc.strip(), end="")
        
