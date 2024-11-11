__author__ = 'Alexander'
import sys
string = sys.stdin.readline().strip()
ideal = {'A','b','d','H','I','M','O','o','p','q','T','U','V','v','W','w','X','x','Y'}

for i in range(int(len(string)/2)):
    if string[i] not in ideal:
        sys.stdout.write("NIE")
        sys.exit()
    elif string[i] == 'b' or string[i] == 'd' or string[i] == 'p' or string[i] == 'q':
        if (string[i] == 'b' and string[-i-1] != 'd') or \
        (string[i] == 'd' and string[-i-1] != 'b') or \
        (string[i] == 'q' and string[-i-1] != 'p') or \
        (string[i] == 'p' and string[-i-1] != 'q'):
            sys.stdout.write("NIE")
            sys.exit()
    elif string[i] != string[-i-1]:
        sys.stdout.write("NIE")
        sys.exit()
sys.stdout.write("TAK")