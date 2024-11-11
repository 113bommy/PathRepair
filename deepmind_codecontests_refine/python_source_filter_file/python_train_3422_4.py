l = 'abcdefghijklmnopqrstuvwxyz'

while True:
    try:
        s = input()
    except:
        exit()
    for d in range(1,27):
        t = s[:-1].translate(str.maketrans(l,l[d:] + l[:d]))
        if 'that' in t or 'this' in t or 'that' in t:
            print(t + '.')
            break

