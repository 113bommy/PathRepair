# s = input()
s = ''.join(['sshh'] * 50000)
to_be_removed = []
cur_char = s[0]
cur_char_cnt = 1
for i, c in enumerate(s):
    if i == 0:
        continue
    if c == cur_char:
        cur_char_cnt += 1
        if cur_char_cnt >= 3:
            to_be_removed.append(i)
    else:
        cur_char = c
        cur_char_cnt = 1

s = [c for c in s]
for i in to_be_removed:
    s[i] = ''
s = ''.join(s)
islands_of_2 = []
cur_char = s[0]
cur_char_cnt = 1
for i, c in enumerate(s):
    if i == 0:
        continue
    if c == cur_char:
        cur_char_cnt += 1
        if cur_char_cnt == 2:
            islands_of_2.append(i)
    else:
        cur_char = c
        cur_char_cnt = 1

if islands_of_2:
    island_to_remove = []
    prev_island = None
    for island in islands_of_2:
        if prev_island and prev_island + 2 == island:
            island_to_remove.append(island)
            prev_island = None
            continue
        else:
            prev_island = island

    s = [c for c in s]
    for i in island_to_remove:
        s[i] = ''

print(''.join(s))