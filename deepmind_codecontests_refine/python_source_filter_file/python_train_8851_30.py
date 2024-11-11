s = input()
c = 0
while True:
    t = input()
    if t == 'END_OF_TEXT': break
    for w in t.split():
        if w == s:
            c += 1
print(c)