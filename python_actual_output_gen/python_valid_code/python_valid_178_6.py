# coding=utf-8

if __name__ == '__main__':
    n = int(input())
    line = str(input())
    if n >= 24 and len(list(set(list(line.lower())))) >= 24:
        print('YES')
    else:
        print('NO')
