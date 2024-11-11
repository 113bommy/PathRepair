for i in range(9):
    print(i)
    s = input()
    normal = {'great', "don't think so", "don't touch me", 'not bad', 'cool'}
    if 'no' not in s:
        print('normal' if s not in normal else 'grumpy')
        break