"""
Shuffle Hashing
"""
t = int(input())
h_list = []
p_list = []
for i in range(t):
    h_list.append(input())
    p_list.append(input())

for i in range(t):
    p = p_list[i]
    h = h_list[i]
    pl = len(p)
    hl = len(h)
    if pl < hl:
        print('No')
        break
    h_text = []
    for letter in h:
        h_text.append(letter)
    h_text.sort()

    for l in range(0,  pl - hl + 1):
        pre_text = p[l: hl + l]
        text = []
        for letter in pre_text:
            text.append(letter)
        text.sort()
        if h_text == text:
            print("Yes")
            break
        if l == pl - hl:
            print('No')
