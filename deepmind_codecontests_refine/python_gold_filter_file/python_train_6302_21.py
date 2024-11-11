ln = int(input())
s = ''
i = 1
while len(s) < ln:
    s += str(i)
    i += 1
print(s[ln-1])

