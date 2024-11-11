s = input()
if s.count('@') != 1 or s.count('/') > 1:
    print('NO')
    exit(0)

pos1 = s.find('@')
pos2 = s.find('/')

#print(pos1)
#print(pos2)
if pos2 == -1: pos2 = len(s)
import re

username = re.compile('(\w){1,16}$')
hostname = re.compile('(\w{1,16}.){0,2}\w{1,16}$')

#print(s[0:pos1])
#print(s[pos2 + 1 : len(s)])
#print(s[pos1 + 1 : pos2])



ok1 = hostname.match(s[pos1 + 1 : pos2])
ok2 = username.match(s[0:pos1])
ok3 = username.match(s[pos2 + 1 : len(s)])


#print(ok1)
#print(ok2)
#print(ok3)

if len(s[pos1 + 1 : pos2]) >= 1 and len(s[pos1 + 1 : pos2])<= 32 and ok1 and ok2 and (pos2 == len(s) or ok3):
    print('YES')
else:
    print('NO')


