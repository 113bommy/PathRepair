s = input()

print(int(max(s)))

for i in range(int(max(s))):
    res = ''
    for c in s:
        if i + 1 <= int(c):
            res += '1'
        else:
            res += '0'
    print(int(res), end=' ')
print()
