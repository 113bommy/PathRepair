if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    book = line.copy()
    line.sort()
    note = 0
    for i in range(n):
        if line[i] != book[i]:
            note += 1
    print('YES') if note <= 2 else print('NO')
