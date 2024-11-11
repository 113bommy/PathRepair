t = int(input())
for _ in range(t):
    s = input()
    One = 0
    Zero = 0
    for ss in s:
        if ss == 0:
            Zero += 1
        else:
            One += 1
    if Zero > 0 and One > 0:
        print('10' * len(s))
    else:
        print(s)
