def main():
    s = input()
    checked = []
    l = len(s)
    mi = l // 2 + 1
    for i in range(l):
        if s[i] not in checked:
            j = i + 1
            m = i + 1
            t = i
            while j < l:
                while j < l and s[t] != s[j]:
                    j += 1
                if j - t > m:
                    m = j - t
                t = j
                j += 1
            if m < mi:
                mi = m
            checked += [s[i]]
    print(mi)

main()
