if __name__ == '__main__':
    n, k = map(int, input().split())
    line = str(input())
    book = dict()
    for it in line:
        book[it] = book.setdefault(it, 0) + 1
    line = list(book.values())
    line.sort(reverse=True)
    rest = 0
    for it in line:
        if k < it:
            rest += k * it
            break
        else:
            rest += it ** 2
            k -= it
    print(rest)
