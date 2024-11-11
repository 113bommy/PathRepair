from collections import defaultdict
import sys
input = sys.stdin.readline
flush = sys.stdout.flush
get_int = lambda : int(input().rstrip())
get_arr = lambda : [int(w) for w in input().split()]


def pb(x):
    print(bin(x)[2:])


def can(a, b):
    for i in range(len(b) - len(a) + 1):
        if b[i] == '0':
            return False
        if b[i:i + len(a)] == a and b[i + len(a):].count('1') == len(b[i + len(a):]):
            return True
    return False


def gl_can(a, b):
    if a == b or b % 2 == 0:
        return a == b

    pos_a = {2 * a + 1}
    while a % 2 == 0:
        a //= 2
    pos_a.add(2 * a + 1)

    b = bin(b)[2:]
    pos_b = {b, b[::-1]}

    return any(can(bin(a)[2:], b) for a in pos_a for b in pos_b)


a, b = get_arr()
# pb(a)
# pb(b)
print("YES" if gl_can(a, b) else "NO")