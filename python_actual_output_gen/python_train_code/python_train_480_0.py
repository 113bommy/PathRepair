def f():
    s = input()
    if s[-1] == 'u':
        print('JAPANESE')
    elif s[-1] == 'o':
        print('FILIPIN')
    elif s[-1] == 'a':
        print('KOREAN')
t = int(input())
for i in range(t):
    f()