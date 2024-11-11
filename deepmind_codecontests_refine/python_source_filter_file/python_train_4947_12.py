a, b = input(), input()
a = '0'*(len(b) - len(a))
b = '0'*(len(a) - len(b))
if a < b:
    print('<')
elif a > b:
    print('>')
else:
    print('=')
