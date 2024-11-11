s = input()

v = 0
h = 0
for ch in s:
    if ch == '0':
        print(f'{v+1} 1')
        v = (v+1)%4
    else:
        print(f'{h*2+1} 4')
        h = (h+1)%4