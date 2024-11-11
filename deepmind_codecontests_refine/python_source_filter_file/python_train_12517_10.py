# https://codeforces.com/problemset/problem/133/A
import sys
#-----------------------------------------------------------------------------#
try:
    sys.stdin = open('inputs.txt', 'r')
    sys.stdout = open('output.txt', 'w')
except:
    pass
finally:
    input = sys.stdin.readline
    print = sys.stdout.write

#-----------------------------------------------------------------------------#

arg = list(input().strip())
yes = {'H', 'Q', '9'}

for i in arg:
    if i in yes:
        print('Yes')
        break
    else:
        pass
else:
    print('NO')
