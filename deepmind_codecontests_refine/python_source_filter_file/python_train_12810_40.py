import sys
a=1
for b in sys.stdin:
 b=b.strip()
 if b=='0':break
 print('Case {a}: {b}')
 a+=1