cnt = 8
pos = list(input())
pos1 = pos[:]
pos[0] = "abcdefgh".index(pos[0]) + 1
pos[1] = int(pos[1])
if pos[0] in [1, 8]:
    cnt -= 3
    if pos[1] in [1, 8]:
        cnt -= 2
elif pos[1] in [1, 8]:
    cnt -= 3
print(pos1, cnt)
