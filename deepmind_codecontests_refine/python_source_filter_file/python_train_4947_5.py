if __name__ == '__main__':
    a = str(input())
    b = str(input())
    la, lb = len(a), len(b)
    if la > lb:
        b = '0' * (la - lb) + b
    elif la < lb:
        a = 'a' * (lb - la) + a
    if a > b:
        print('>')
    elif a < b:
        print('<')
    else:
        print('=')
