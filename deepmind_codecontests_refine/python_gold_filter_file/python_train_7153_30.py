s = input()
for i in range(len(s) - 2):
    if s[i:i + 3] in {'ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA'}:
        print('Yes')
        exit(0)
print('No')
