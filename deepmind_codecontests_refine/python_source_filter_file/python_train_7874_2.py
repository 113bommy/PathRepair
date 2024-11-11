import sys
def check(s):
    if s == 'no':
        return 'dn'
    elif s in ['great!','don\'t think so','don\'t touch me!','not bad','cool']:
        return 'n'
    else:
        return 'g'
print(0)
sys.stdout.flush()
t = check(input())
for i in range(1,10):
    if t == 'dn':
        print(i)
        sys.stdout.flush()
        t = check(input())
    elif t == 'n':
        print('normal')
        sys.stdout.flush()
        sys.exit(0)
    else:
        print('grumpy')
        sys.stdout.flush()
        sys.exit(0)
