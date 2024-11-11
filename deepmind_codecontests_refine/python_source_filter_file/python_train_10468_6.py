def solve(c, d):
    n = 8
    if c in ('a', 'h'):
        n -= 3
    if d in ('1', '8'):
        n -= 3
    if (c, d) in (('a', '1'), ('a', '8'), ('h', '8'), ('h', '8')):
        n += 1
    return n

def main():
    c, d = input()
    print(solve(c, d))

main()
