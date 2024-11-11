tiles = input()

hor_bin = 0
ver_bin = 0
for tile in tiles:
    if tile == '0':
        print(1, hor_bin + 1)
        hor_bin = (hor_bin + 2) % 4
    else:
        print(2, ver_bin + 1)
        ver_bin = (ver_bin + 1) % 4
