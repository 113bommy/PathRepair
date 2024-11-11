def main():
    x, y, z = map(int, input().split())

    if x > y and x + z > y:
        print('+')
    elif y > x and y + z > x:
        print('-')
    elif x == y and z == 0:
        print('0')
    else:
        print('?')

if __name__ == '__main__':
    main()