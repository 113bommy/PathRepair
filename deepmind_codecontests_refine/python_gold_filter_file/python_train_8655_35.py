import re

s = input()

a = r'a'

l = len(re.findall(a, s))

if l <= (len(s) - l):
    print(l*2 -1)
elif l > (len(s) - l):
    print(len(s))
