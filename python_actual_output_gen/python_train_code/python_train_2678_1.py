n = int(input())
ss = []
for i in range(n):
    input()
    ss += [input()]

for i in range(n):
    s = list(map(int, ss[i].split(' ')))
    max_idx = -1
    for j in range(1, len(s)+1):
        idx = s.index(j)
        if max_idx == idx-1:
            max_idx = idx
        elif max_idx < idx:
            s.insert(max_idx+1, s.pop(idx))
            max_idx = idx-1
        else:
            continue
    print(''.join(list(map(str, s))))
    