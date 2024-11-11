text = input()
ALF = 'HQ9+'
count = 0

for ch in text:
    if ch in ALF:
        print('YES')
        break
    else:
        count += 1

if count == len(text):
    print('NO')