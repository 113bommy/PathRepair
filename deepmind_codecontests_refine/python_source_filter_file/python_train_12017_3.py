def main():
    exp = input()
    a_plus_b, c = exp.split('=')
    a, b = a_plus_b.split('+')
    if len(a) + len(b) == len(c):
        print(exp)
    elif len(a) + len(b) == len(c) - 2:
        print(
            '|' * (len(a) + 1) + '+' + '|' * len(b) + '=' + '|' * (len(c) - 1))
    elif len(a) + len(b) == len(c) + 2:
        if len(a) > 2:
            print('|' * (len(a) - 1) + '+' + '|' * len(b) + '=' + '|' * (
                        len(c) + 1))
        elif len(b) > 2:
            print('|' * len(a) + '+' + '|' * (len(b) - 1) + '=' + '|' * (
                        len(c) + 1))
        else:
            print("Impossible")
    else:
        print("Impossible")


if __name__ == '__main__':
    main()
