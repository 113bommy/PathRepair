if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    minx = line[0]
    book = dict()
    for it in line:
        book[it] = book.setdefault(it, 0) + 1
        minx = min(minx, it)
    if book[minx] > 1:
        print('Still Rozdil')
    else:
        print(line.index(minx) + 1)
