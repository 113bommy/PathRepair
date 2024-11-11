for _ in range(int(input())):
    t = list(map(int,input().split(' ')))
    print('YES' if t[0] - 1 != t[1] else 'NO')