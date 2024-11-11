import sys
a=1
for b in sys.stdin:b=b.strip()
 if b=='0':break
 print(f'Case {a}: {b}')
 a+=1