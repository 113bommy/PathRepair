import sys
i=1
for a in sys.stdin:
 if a.strip()=='0':break
 print(f'Case {i}: {a}')
 i+=1