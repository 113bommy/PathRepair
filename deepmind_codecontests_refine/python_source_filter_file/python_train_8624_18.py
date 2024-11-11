from collections import defaultdict


def ok(l, s):
    for i in range(len(s) * 2):
        now = i % len(l)
        pre = now - 1
        nex = (now + 1) % len(l)
        if (l[now] == -1 and s[now] == 'x') or (l[now] == 1 and s[now] == 'o'):
            if l[nex] is None:
                l[nex] = l[pre]
            else:
                if l[nex] != l[pre]:
                    return False
        else:
            if l[nex] is None:
                l[nex] = -1 * l[pre]
            else:
                if l[nex] != -1 * l[pre]:
                    return False

    return True


def main():
    N = int(input())
    s = input()

    for x in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
        l = [None] * N
        l[-1], l[0] = x[0], x[1]
        if ok(l, s):
            print("".join(['w' if x == -1 else 's' for x in l]))
            return
    print(-1)


if __name__ == '__main__':
    main()
