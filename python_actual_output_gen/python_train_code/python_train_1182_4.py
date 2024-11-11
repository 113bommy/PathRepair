import sys
a='abcdefghijklmnopqrstuvwxy'
for b in sys.stdin:
 for i in range(26):
  c=''.join(a[ord(e)-97-i]if e in a else e for e in b)
  if any(('the'in c,'this'in c,'that'in c)):print(c)
