s=input()
x=s.count('n')
if x>3:
    print( min((s.count('n')+1)//3,s.count('i'),s.count('e')//3,s.count('t')))
else :
    print( min(s.count('n')//3,s.count('i'),s.count('e')//3,s.count('t')))