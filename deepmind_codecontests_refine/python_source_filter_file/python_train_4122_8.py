s = input()
res = str(eval(s))
for c in res:
    print('+' * ord(c) + '.', end='')
print()
