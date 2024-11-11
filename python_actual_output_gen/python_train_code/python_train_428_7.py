s = input()
i = -1

for ch in s:
    i = s.find(ch, i+1)
    if i < 0:
        print('NO')
        break
else:
    print('YES')