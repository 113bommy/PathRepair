n = int(input())
def print_from_l(l):
    print(''.join(map(lambda s:chr(97+s), l)))
def g(l):
    if len(l) == n:
        print_from_l(l)
    else:
        for i in range(max(l)+2):
            g(l + [i])
g([0])