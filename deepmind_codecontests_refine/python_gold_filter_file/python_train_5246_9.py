def main():
    n, s = int(input()), input()
    r, l = s.find('R') + 1, s.rfind("L") + 1
    if not r:
        print(l, l - s.count('L'))
    elif not l  :
        print(r, r + s.count('R'))
    else:
        print(r, s.find('RL') + 1)


if __name__ == '__main__':
    main()
