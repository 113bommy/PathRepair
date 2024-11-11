if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    v = sum(line)
    if v > 0:
        print('YES')
        print(1)
        print('1 ' + str(n))
    else:
        x = 0
        for i in range(n):
            if line[i] != 0:
                x = i + 1
                break
        if x > 0:
            print('YES')
            print(2)
            print('1 ' + str(x))
            print(str(x + 1) + ' ' + str(n))
        else:
            print('NO')
