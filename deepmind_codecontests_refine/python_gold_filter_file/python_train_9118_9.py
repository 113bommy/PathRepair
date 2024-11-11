input()
s = input().strip()
n = 0
for c in s:
    if c == '1':
        n += 1
    else:
        print(n, end='')
        n = 0
print(n)