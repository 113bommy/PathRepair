for _ in range(int(input())):
    s = input()
    if s.endswith('po'):
        print('FILLIPINO')
    elif s.endswith('mnida'):
        print('JAPANESE')
    else:
        print('KOREAN')