import re

s = input()

a = r'a'

l = len(re.findall(a, s))

if l <= (len(s) - l):
    print(l + l//2)
elif l > (len(s) - l):
    print(len(s))
