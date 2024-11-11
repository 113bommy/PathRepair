import sys
i=1
for a in sys.stdin:a=a.strip()
 if a=='0':break
 print(f'Case {i}: {a}')
 i+=1