from sys import stdin, stdout
f = list(stdin.readline().strip())
label = False
chars = {'X', 'Y', 'Z', 'T', 'U', 'V', 'W', 'P', 'Q', 'R', 'S', 'L', 'M', 'N', 'O', 'H', 'I', 'J', 'K', 'D', 'E', 'F', 'G', 'A', 'B', 'C'}

if len(f) >= 26:
    for i in range(len(f)):
        if f[i: i + 26].count('?') + len(set(f[i: i + 26]) - {'?'}) == 26:
            label = True
            challengers = set(f[i: i + 26]) - {'?'}
            ind = i

if label:
    for i in range(len(f)):
        if ind + 25 >= i >= ind and f[i] == '?':
            for char in chars:
                if char not in challengers:
                    challengers.add(char)
                    f[i] = char
                    break
        elif f[i] == '?':
            f[i] = 'A'
    stdout.write(''.join(f))
else:
    stdout.write('-1')