x = input()
pos = 0
ok = True
while pos < len(x):
    if pos + 2 < len(x):
        if x[pos:pos+3] == '144':
            pos += 3
            continue
    elif pos + 1 < len(x):
        if x[pos:pos+2] == '14':
            pos += 2
            continue
    if x[pos] == 1:
        pos += 1
    else:
        ok = False
        break

print('YES' if ok else 'NO')