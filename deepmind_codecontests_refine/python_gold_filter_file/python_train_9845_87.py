

if __name__ == '__main__':
    n = input()
    l = [ele for ele in input()]

    if l.count('A') > l.count('D'):
        print('Anton')
    elif l.count('D') > l.count('A'):
        print('Danik')
    else:
        print('Friendship')

