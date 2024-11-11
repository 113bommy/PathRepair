s = input()

map = [[0, 0, 0, 0] for _ in range(4)]
zero_idx = 0
one_idx = 1
for e in s:
    if e == '0':
        print(1, zero_idx + 1)
        zero_idx = (zero_idx + 1) % 4
    else:
        print(3, one_idx)
        one_idx = (one_idx + 2) % 4
