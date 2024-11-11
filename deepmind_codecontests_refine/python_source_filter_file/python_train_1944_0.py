a, b = [int(x) for x in input().split()]
c = 0
if a < b:   
    c = 1
    a, b = b, a
if a > pow(a, a / b):
    print('>' if not c else '<')
elif a < pow(b, a / b):
    print('<' if not c else '>')
else:
    print('=')
