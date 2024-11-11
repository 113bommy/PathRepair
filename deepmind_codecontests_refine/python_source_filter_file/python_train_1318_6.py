def main():
    n=input()
    line=n.count('-')
    hill=n.count('o')
    if hill==0:
        print('NO')
        return
    print('YES' if line%hill==0 else 'NO')


if __name__ == '__main__':
    main()
