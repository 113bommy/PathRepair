import sys
good = {'great', 'notbad', 'cool', 'donttouch me', 'idontthink so'}
for i in range(10):
    print(i)
    sys.stdout.flush()
    s = input()
    if s == 'noway' or (s != 'no' and s not in good):
        print('grumpy')
        exit(0)
    elif s in good:
        print('normal')
        exit(0)