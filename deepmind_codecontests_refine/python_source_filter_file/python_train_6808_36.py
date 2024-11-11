import re
s = input()
s = re.sub('--','2',s)
print(s,1)
s = re.sub('-.','1',s)
print(s,2)
s = '0'.join(s.split('.'))
print(s,3)