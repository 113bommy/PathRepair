def contains(s, frm, p, pos):
    if pos == len(p):
        return True
    ind = s.find(p[pos], frm)    
    if ind < 0:
        return False
    else:
        return contains(s, ind + 1, p, pos + 1)

print(('YES', 'NO')[contains(input(), 0, 'hiedi', 0)])
