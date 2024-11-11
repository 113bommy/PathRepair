s = input()
n = len(s)
first_h = False
first_v = False
for i in range(n):
    if s[i] == '1':
        if first_v:
            print(3, 1)
            first_v = False
        else:
            print(1, 1)
            first_v = True
    else:
        if first_h:
            print(4, 1)
            first_h = False
        else:
            print(4, 3)
            first_h = True
