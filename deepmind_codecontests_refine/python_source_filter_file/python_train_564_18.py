

def main():

    s = input()
    t = input()

    k = 0
    for i in range(len(s)):
        if k < len(t) and s[i] == t[k]:
            k += 1

    if k == len(t):
        print('automaton')
        return

    sd = {}
    for c in s:
        if c not in sd:
            sd[c] = 0
        sd[c] += 1

    td = {}
    for c in t:
        if c not in td:
            td[c] = 0
        td[c] += 1

    status = True
    for c in t:
        if c in sd and td[c] == sd[c]:
            pass
        else:
            status = False

    if status:
        if len(s) == len(t):
            print('array')
        else:
            print('both')
    else:
        print('need tree')




if __name__ == '__main__':
    main()


