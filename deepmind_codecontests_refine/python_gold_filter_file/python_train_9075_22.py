from sys import stdin, stdout

s = stdin.readline()

four = s.count('4')
sev = s.count('7')



if four + sev ==0:
    stdout.write('-1')
elif four >= sev:
    stdout.write('4')
else:
    stdout.write('7')