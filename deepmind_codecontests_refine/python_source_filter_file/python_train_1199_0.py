def unionStrings(x, y):
    if x in y:
        return y
    if y in x:
        return x
    if x[0] in y:
        index = y.index(x[0])
        return y[:index] + x
    if y[0] in x:
        index = x.index(y[0])
        return  x[:index] + y
    if x[-1] in y:
        index = y.index(x[-1])
        return x + y[index+1 :]
    if y[-1] in x:
        index = x.index(y[-1])
        return y + x[index + 1:]
    return ''

line_number = int(input())
lines = [input() for _ in range(line_number)]
lines = [line for line in set(lines)]
is_changes = True
while is_changes:
    is_changes = False
    for line in lines:
        for string in lines:
            if string != line:
                union = unionStrings(line, string)
                if union:
                    lines.remove(line)
                    lines.remove(string)
                    lines.append(union)
                    is_changes = True
            if is_changes:
                break
print(''.join(lines))