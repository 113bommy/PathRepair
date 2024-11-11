s = input()

v = 0
h = 0
for ch in s:
    if ch == '0':
        print(f'1 {v+1}')
        v = (v+1)%4
    else:
        print(f'4 {h*2+1}')
        h = (h+1)%4