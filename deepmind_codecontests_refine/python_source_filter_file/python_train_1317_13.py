import re
n = int(input()) ;s = input()
t = re.sub(r'^(.+)\1.*', r'\1', s)
print(t)
if len(t) == len(s):
	print(len(s))
else:
	print(len(s) - len(t) + 1)