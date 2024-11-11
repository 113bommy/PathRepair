if __name__ == '__main__':
    inp = map(int, input().split())
    max_inp = max(inp)
    if max_inp == 1:
        print('1')
    elif max_inp == 2:
        print('5/6')
    elif max_inp == 3:
        print('2/3')
    elif max_inp == 4:
        print('1/2')
    elif max_inp == 5:
        print('1/3')
    elif max_inp == 6:
        print('1/6') 