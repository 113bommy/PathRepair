import string
import sys

a = string.ascii_lowercase
key = str.maketrans(a, a[1:] + a[:1])

for s in sys.stdin:
    for i in range(1, 27):
        s = s.translate(key)
        if 'the' in s or 'this' in s or 'that' in s:
            break
    print(s)