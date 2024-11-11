def make_them_same(n, s, t):
    invs = [(s[i], t[i]) for i in range(n) if s[i] != t[i]]
    if len(invs) == 0:
        return 'Yes'
    if len(invs) == 2 and len(set(s)^set(t)) in [1, 2] and invs[0] == invs[1]:
        return 'Yes'
    return 'No'


if __name__ == '__main__':
    q = int(input())
    for i in range(q):
        n = int(input())
        s = input()
        t = input()
        print(make_them_same(n, s, t))