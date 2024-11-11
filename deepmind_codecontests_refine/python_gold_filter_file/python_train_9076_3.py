n = int(input())
while n > 0:
    working = set()
    last, count = None, 0
    for c in list(input()) + [None]:
        if c == last:
            count += 1
        else:
            if count & 1 and last is not None:
                working.add(last)
            count = 1
        last = c
    print(''.join(sorted(working)))
    n -= 1
