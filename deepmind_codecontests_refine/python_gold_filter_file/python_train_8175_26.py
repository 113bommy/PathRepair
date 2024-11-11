s = input()
n = len(s) + 1
sym = ['A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y']
prs = [('b', 'd'), ('d', 'b'), ('p', 'q'), ('q', 'p')]

for i in range(n // 2):
    if s[i] in sym:
        if s[i] != s[-i - 1]:
            print("NIE")
            exit()
    elif (s[i], s[-i - 1]) not in prs:
        print("NIE")
        exit()

print("TAK")