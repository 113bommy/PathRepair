a = list(map(str, input()))
b = int(input())

for i in range(len(a)):
    if a[i] == 'a':
        continue
    else:
        s = ord(a[i]) - 96
        if 27 - s <= b:
            a[i] = 'a'
            b -= 27 - s

if b != 0:
    a[-1] = chr(((ord(a[-1]) - 96 + b) % 27) + 96)

print(''.join(a))