import os

is_dev = 'vscode' in os.environ

if is_dev:
    inF = open('in.txt', 'r')
    outF = open('out.txt', 'w')

def ins(r):
    return list(map(int, r.split(' ')))

def input_():
    if is_dev:
        return inF.readline()[:-1]
    else:
        return input()

def print_(data):
    if is_dev:
        return outF.write(str(data)+'\n')
    else:
        return print(data)

# Main:
for _ in range(int(input_())):
    n = int(input_())
    if n == 36:
        print_('YES')
        print_('6 10 15 5')
    elif n == 40:
        print_('YES')
        print_('6 14 15 5')
    elif n == 44:
        print_('YES')
        print_('6 10 15 13')
    elif n > 30:
        print_('YES')
        print_(f'6 10 14 {n - 30}')
    else:
        print_('NO')
    
if is_dev:
    print(open('out.txt', 'r').read() == open('outactual.txt', 'r').read())
