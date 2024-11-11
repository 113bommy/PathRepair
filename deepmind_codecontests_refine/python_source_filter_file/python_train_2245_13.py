def main():
    n, k = list(map(int, input().split()))
    s = input()
    for i, c in enumerate(s):
        if c == 'G':
            g = i
        if c == 'T':
            t = i
    if t < g:
        t, g = g, t
    if g-t % k != 0:
        print('NO')
        return
    for i in range(g, t, k):
        if s[i] == '#':
            print ('NO')
            return
    print ('YES')

main()
