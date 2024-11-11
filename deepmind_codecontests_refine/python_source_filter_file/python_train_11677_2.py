import sys
ints = (int(x) for x in sys.stdin.read().split())

def solve(n, m):
    for j in range(m//2):
        for i in range(n):
            yield (i,j)
            yield (n-1-i, m-1-j)
    if m%2==1:
        for i in range(n//2):
            yield (i, m//2)
            yield (n-1-i, m//2)
        if n%2==1:
            yield (n//2, m//2)
    return


def main(n, m):
    ans = ['{} {}'.format(i,j) for i,j in solve(n, m)]
    print('\n'.join(ans))
    return

while 1:
    try: n, m = next(ints), next(ints)
    except StopIteration: break
    main(n,m)
