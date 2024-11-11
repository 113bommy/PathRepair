def main():
    n = int(input())
    s = input()
    eight = 0
    for i in range(n-11):
        if s[i] == '8':
            eight += 1

    if eight >= (n-11)//2:
        print('YES')
    else:
        print('NO')

main()
