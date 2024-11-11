s = input().rstrip()

g = [
    [False, False, False, False],        
    [False, False, False, False],        
    [False, False, False, False],        
    [False, False, False, False],        
]

i = 0
left = False
while i < len(s):
    c = s[i]
    if c == '0':
        if g[0][0] == False:
            print(1, 1)
            g[0][0] = True
        else:
            g[0][0] = False
            print(3, 1)
    else:
        r = 0
        while r < 4:
            if g[r][2] == False:
                g[r][2] = True
                print(r + 1, 2)
                break
            r += 1
        if r == 4:
            print(4, 2)
            g[0][2] = False
            g[1][2] = False
            g[2][2] = False
            g[3][2] = False
    i += 1
