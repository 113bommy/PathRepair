import re

def letter_to_num(s):
    ret = 0
    for c in s:
        ret = ret * 26 + (ord(c) - ord('A') + 1)
    return ret

def num_to_letter(d):
    ret = ''
    while int(d) != 0:
        ret = chr((int(d) - 1) % 26 + ord('A')) + ret
        d = int(d) / 26
    return ret

n = int(input())
for i in range(n):
    s = input()
    m = re.match("R(\d+)C(\d+)", s)
    if m is not None:
        print('%s%s' % (num_to_letter(m.group(2)), m.group(1)))
        continue

    m = re.match("([A-Z]+)(\d+)", s)
    if m is not None:
        print('R%dC%d' % (int(m.group(2)), letter_to_num(m.group(1))))
