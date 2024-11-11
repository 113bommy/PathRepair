def main():
    n = int(input())
    (l, r) = (int(-1e12), int(1e12))
    for i in range(n):
        (s, x, a) = input().split(' ')
        if (s == '>=' and a == 'Y') or (s == '<' and a == 'N'):
            l = max(l, int(x))
        if (s == '<=' and a == 'Y') or (s == '>' and a == 'N'):
            r = min(r, int(x))
        if (s == '>' and a == 'Y') or (s == '<=' and a == 'N'):
            l = max(l, int(x) + 1)
        if (s == '<' and a == 'Y') or (s == '>=' and a == 'N'):
            r = min(r, int(x) - 1)
    if l <= r:
        return l
    return "Impossible"
print(main())
