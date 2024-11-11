import sys

for i in range(0, 10):
    print(i)
    sys.stdout.flush()
    res = input()
    if res != 'no':
        if res in ['great', "don't think so", "don't touch me", 'not bad', 'cool', 'great']:
            print('normal')
        else:
            print('grumpy')
        sys.stdout.flush()
        exit()