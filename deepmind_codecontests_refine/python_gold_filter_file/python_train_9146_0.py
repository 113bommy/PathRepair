s = input().split()
ss = []
for w in s:
    a = w.find('apple')
    p = w.find('peach')
    if a != -1:
        w = w.replace('apple','peach')
    elif p != -1:
        w = w.replace('peach','apple')
    ss.append(w)
print(' '.join(ss))