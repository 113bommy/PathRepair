import sys

fin = sys.stdin
fout = sys.stdout
s = fin.readline().strip()
res = 0
if (s == 'a1' or s == 'a8' or s == 'h1' or s == 'h8'):
    res = 2
elif (s[0] == 'a' or s[0] == 'h' or s[1] == '1' or s[1] == '8'):
    res = 5
else:
    res = 8
fout.write(str(res))
