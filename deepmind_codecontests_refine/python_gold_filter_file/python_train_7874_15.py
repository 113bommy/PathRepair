import sys
good = {'great', 'not bad', 'cool', 'don\'t touch me', 'don\'t think so'}
for i in range(10):
    print(i)
    sys.stdout.flush()
    s = input()
    if s == 'no way' or (s != 'no' and s not in good):
        print('grumpy')
        exit(0)
    elif s in good:
        print('normal')
        exit(0)