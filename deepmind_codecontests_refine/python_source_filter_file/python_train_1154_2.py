n, m = map(int, input().split())
a = [int(x) for x in input().split()]
pages = 0

for i in a:
    pages += i
    print(pages // m, end = ' ')
    if pages > m:
        pages %= m
