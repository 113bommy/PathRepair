n, m = [int(x) for x in input().split(' ')]

color = ['C', 'M', 'Y']
pixels = []
i = 0

while i < n:
    pixels.append(input().split(' '))
    i += 1

bool_color = False

for pix in pixels:
    for p in pix:
        if p in color:
            bool_color = True

if bool_color:
    print('#Color')
else:
    print('Black&White')


